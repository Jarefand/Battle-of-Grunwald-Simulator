#include "Map.h"
#include <cstdlib>

/// @file Map.cpp
/// @brief Plik Ÿródowy klasy Map

/// @brief Dekonstruktor klasy Map
Map::~Map()
{
    if (!getarmia_pol().empty())
    {
        for (int i = 0; i < armia_pol.size(); i++)
        {
            delete armia_pol[i];
        }
        
    }
    else if (!getarmia_krzyz().empty())
    {
        for (int i = 0; i < armia_krzyz.size(); i++)
        {
            delete armia_krzyz[i];
        }
    }
    armia_pol.clear();
    armia_krzyz.clear();

}

/// @brief Dodaj now¹ jednostkê Polskiej armii
void Map::dodajJednostkePolsce()
{
    Jednostka* j;
    aktualizuj_mape_walki();
    int los;
    los = rand() % 3;

    switch (los)
    {
    case 0:
        j = new Pospolite_rusz(7, 7, "Polska");
        ustawienie_jednostek(j);
        break;
    case 1:
        j = new Jazda(7, 8, "Polska");
        ustawienie_jednostek(j);
        break;
    case 2:
        j = new Zbrojni(7, 9, "Polska");
        ustawienie_jednostek(j);
        break;
    }
    
    armia_pol.push_back(j);
}

/// @brief Dodaj nowa jednostkê armii Krzy¿ackiej
void Map::dodajJednostkeKrzyzakom()
{
    aktualizuj_mape_walki();
    Jednostka* j;

    int los;
    los = rand() % 3;

    switch (los)
    {
    case 0:
        j = new Pospolite_rusz(8,6, "Krzyzacy");
        ustawienie_jednostek(j);
        break;
    case 1:
        j = new Jazda(8, 7, "Krzyzacy");
        ustawienie_jednostek(j);
     
        break;
    case 2:
        j = new Zbrojni(8, 8, "Krzyzacy");
        ustawienie_jednostek(j);
        break;
    }
    armia_krzyz.push_back(j);
}

/// @brief Ustaw pozycjê jednostki na pocz¹tku symulacji
/// @param oddzial Jednostka, która ma zostaæ ustawiona
void Map::ustawienie_jednostek(Jednostka* oddzial)
{

    if (oddzial->get_armia() == "Krzyzacy")
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0;j < COL; j++)
            {
                if (oddzial->isUnBlocked(mapa_walki, i, j))
                {
                    Pair ustaw = make_pair(i, j);
                    oddzial->przemieszczenie(ustaw);  
                    return;
                }
            }
        }
      
    }
    else if (oddzial->get_armia() == "Polska")
    {
        for (int i = ROW -1; i > ROW -4; i--)
        {
            for (int j = 0; j < COL; j++)
            {
                if (oddzial->isUnBlocked(mapa_walki, i, j))
                {
                    Pair ustaw = make_pair(i, j);
                    oddzial->przemieszczenie(ustaw);
                    return;
                }
            }
        }
    }
   
}


/// @brief Zwraca jednostki Polskiej armii
/// @return Tablica polskich jednostek
vector <Jednostka*> Map::getarmia_pol()
{
    return armia_pol;
}

/// @brief Zwraca jednostki Krzy¿ackiej armii
/// @return Tablica krzy¿ackich jednostek
vector <Jednostka*> Map::getarmia_krzyz()
{
    return armia_krzyz;
}

/// @brief Znajdujê najkrótsz¹ œcie¿kê do wroga
/// @param oddzial jedstka dla, której najktórsza œcie¿ka do wroga ma zostaæ odnaleziona
/// @return zwraca œcie¿kê(pozycjê po pozycji, które musi pokonaæ jednostka) w postaci stosu
stack <Pair> Map::znajdz_przeciwnika(Jednostka* oddzial)
{ 
   
        string arm = oddzial->get_armia();
        stack <Pair> sciezka;
        stack <Pair> sciezka2;
        int max = ROW * COL;
        if (!getarmia_krzyz().empty() && !getarmia_pol().empty())
        {
            if (arm == "Polska")
            {
                sciezka = oddzial->aStarSearch(mapa_walki, oddzial->get_x(), oddzial->get_y(), getarmia_krzyz()[0]->get_x(), getarmia_krzyz()[0]->get_y());

                for (int i = 1; i < getarmia_krzyz().size(); i++)
                {
                    sciezka2 = oddzial->aStarSearch(mapa_walki, oddzial->get_x(), oddzial->get_y(), getarmia_krzyz()[i]->get_x(), getarmia_krzyz()[i]->get_y());

                    if (sciezka2.size() < sciezka.size() && sciezka2.size() > 2)
                    {
                        sciezka = sciezka2;
                    }

                }
                return sciezka;
            }
            else
            {
                sciezka = oddzial->aStarSearch(mapa_walki, oddzial->get_x(), oddzial->get_y(), getarmia_pol()[0]->get_x(), getarmia_pol()[0]->get_y());
                for (int i = 1; i < getarmia_pol().size(); i++)
                {
                    sciezka2 = oddzial->aStarSearch(mapa_walki, oddzial->get_x(), oddzial->get_y(), getarmia_pol()[i]->get_x(), getarmia_pol()[i]->get_y());

                    if (sciezka2.size() < sciezka.size() && sciezka2.size() > 2)
                    {
                        sciezka = sciezka2;
                    }

                }
                return sciezka;
            }
        }
        return sciezka;
}

/// @brief aktualizuje mapê walki(nanosi poprawki pozycji po przemieszczeniu jednostek)
void Map::aktualizuj_mape_walki()
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            mapa_walki[i][j] = grid[i][j];
        }
    }
    int x_pom;
    int y_pom;

    for (int i = 0; i < getarmia_krzyz().size(); i++)
    {
        x_pom = getarmia_krzyz()[i]->get_x();
        y_pom = getarmia_krzyz()[i]->get_y();

        mapa_walki[y_pom][x_pom] = 5;
    }

    for (int i = 0; i < armia_pol.size(); i++)
    {
        x_pom = getarmia_pol()[i]->get_x();
        y_pom = getarmia_pol()[i]->get_y();

        mapa_walki[y_pom][x_pom] = 5;
    }
}

/// @brief Sprawdza czy w zasiegu ataku jednostki znajduje siê wróg, jeœli tak to atakuje wroga(zadaje mu obra¿enia)
/// @param oddzial Jednostka dla której sprawdzamy czy mo¿e zatakowaæ
/// @return Zwraca czy jakaœ jednostka wroga zosta³a zatakowana 
bool Map::czy_w_zasiegu(Jednostka* oddzial)
{
    string arm = oddzial->get_armia();
    int x = oddzial->get_x();
    int y = oddzial->get_y();
    int zas = oddzial->get_zas();
    int xp, yp;
    int odl;
    int czy_zos;
    if (arm == "Krzyzacy")
    {
        for (int i = 0; i < getarmia_pol().size(); i++)
        {
            xp = getarmia_pol()[i]->get_x();
            yp = getarmia_pol()[i]->get_y();
            odl = 10 * sqrt(((x - xp) * (x - xp)) + ((y - yp) * (y - yp)));
            if (odl <= zas)
            {
                czy_zos = getarmia_pol()[i]->odbierz_obrazenia(oddzial);
                if (!czy_zos)
                {
                    delete armia_pol[i];
                    armia_pol.erase(armia_pol.begin() + i);
                }
                return 1;
            }
        }
    }
    else
    {
        for (int i = 0; i < getarmia_krzyz().size(); i++)
        {
            xp = getarmia_krzyz()[i]->get_x();
            yp = getarmia_krzyz()[i]->get_y();
            odl = 10 * sqrt(((x - xp) * (x - xp)) + ((y - yp) * (y - yp)));
            if (odl <= zas)
            {
                czy_zos = getarmia_krzyz()[i]->odbierz_obrazenia(oddzial);
                if (!czy_zos)
                {
                    delete armia_krzyz[i];
                    armia_krzyz.erase(armia_krzyz.begin() + i);
                }
                return 1;
            }

        }
    }
    return 0;
}

/// @brief Zwraca w postaci liczbowej typ terenu w danej pozycji na mapie
/// @param i Pozycja x na mapie
/// @param j Pozycja y na mapie
/// @return Wartoœæ terenu w postaci liczbowej
int Map::get_grid(int i, int j)
{
    return grid[i][j];
}