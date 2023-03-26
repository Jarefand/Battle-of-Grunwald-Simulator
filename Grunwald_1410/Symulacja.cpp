#include "Symulacja.h"

/// @file Symulacja.cpp
/// @brief Plik Ÿródowy klasy Symulacja

/// @brief Konstruktor klasy Symulacja
/// @param cze czêstotliowœæ odœwierzani symulacji
Symulacja::Symulacja(int cze)
{
	mapa = new Map;
	czestotliwosc = cze;
	start = clock();
	now = 0;
	elapsed = 0;
	pobranie_danych();
	dodawanie_jednostek();
	okno = new sf::RenderWindow(sf::VideoMode(1600, 960), "Symulator bitwy pod Grunwaldem", sf::Style::Default, sf::ContextSettings(24, 8, 4));
	graf = new CGrafika(mapa, okno);
}

/// @brief Dekonstruktor klasy symulacja
Symulacja::~Symulacja()
{
	delete mapa;
	delete okno;
	delete graf;
}

/// @brief Uruchomienie symulacji od momentu zamkniêcia okna
void Symulacja::uruchom()
{
	while (okno->isOpen())
	{
		Event event;
		while (okno->pollEvent(event))
		{
			if (event.type == Event::Closed)
				okno->close();
		}
		okno->clear();
		graf->rysowanie_mapy();
		odswierz_cz();
		okno->display();
	}

}

/// @brief Pojedynczy cykl symulacji(opoznienie)
void Symulacja::odswierz_cz()
{
	do {
		now = clock();
		elapsed = double(now - start) / CLOCKS_PER_SEC;
	} while (elapsed < (1.0 / double(czestotliwosc)));
	start = now;
	odswierz();

}

/// @brief Funkcja odpowiadaj¹ca za wykonanie dzia³añ przez jednostki(atakowania b¹dŸ ruchu)
void Symulacja::odswierz()
{
	
	bool czy_atak;
	stack <Pair> sciezka;
	stack <Pair> sciezka2;
	for (int i = 0; i < mapa->getarmia_krzyz().size(); i++)
	{		
		

		czy_atak = mapa->czy_w_zasiegu(mapa->getarmia_krzyz()[i]);
		if(czy_atak == 0)
		{
			sciezka = mapa->znajdz_przeciwnika(mapa->getarmia_krzyz()[i]);
			sciezka2 = sciezka;
			if (!sciezka.empty() && sciezka.size() > 2)
			{
				sciezka.pop();
				mapa->getarmia_krzyz()[i]->przemieszczenie(sciezka.top());
			}
		}
		
		mapa->aktualizuj_mape_walki();
		if (koniec_gry())
		{
			break;
		}
	}

	for (int i = 0; i < mapa->getarmia_pol().size(); i++)
	{

		czy_atak = mapa->czy_w_zasiegu(mapa->getarmia_pol()[i]);
		if(czy_atak == 0)
		{
			sciezka = mapa->znajdz_przeciwnika(mapa->getarmia_pol()[i]);
			if (!sciezka.empty() && sciezka.size() > 2)
			{
				sciezka.pop();
				mapa->getarmia_pol()[i]->przemieszczenie(sciezka.top());
			}
		}
		mapa->aktualizuj_mape_walki();
		if (koniec_gry())
		{
			break;
		}	
	}

	graf->rysuj_oddzialy(mapa);
	koniec_gry();
}

/// @brief Pobieranie danych pocz¹tkowych w celu zainicjalizowania symulacji
void Symulacja::pobranie_danych()
{
	bool dane_OK = true;
	string dane;
	int ilosc;
	int i = 0;

	cout << "Podaj ilosc jednostek polskich w zakresie [1-25]:";
	cin >> dane;

	do{
		dane_OK = true;
		for (int i = 0; i < dane.size(); i++)
		{
			if (dane[i] < '0' || dane[i] > '9')
			{
				dane_OK = false;
			}
		}

		if (dane_OK)
		{
			ilosc = stoi(dane);
			if (ilosc < 1 || ilosc > 25)
			{
				dane_OK = false;
			}
		}

		if (!dane_OK)
		{
			system("cls");
			cout << "Podaj poprawna wartosc [1-25]: ";
			dane.clear();
			cin >> dane;
		}
		i++;
	} while (!dane_OK || i < 6);

	if (!dane_OK)
	{
		ilosc = 20;
	}
	ilosc_jednostek_pol = ilosc;

	cout << "Podaj ilosc jednostek krzyzackich w zakresie [1-25]:";
	cin >> dane;
	i = 0;
	do {
		dane_OK = true;
		for (int i = 0; i < dane.size(); i++)
		{
			if (dane[i] < '0' || dane[i] > '9')
			{
				dane_OK = false;
			}
		}

		if (dane_OK)
		{
			ilosc = stoi(dane);
			if (ilosc < 1 || ilosc > 25)
			{
				dane_OK = false;
			}
		}

		if (!dane_OK)
		{
			system("cls");
			cout << "Podaj poprawna wartosc [1-25]: ";
			dane.clear();
			cin >> dane;
		}
		i++;
	} while (!dane_OK || i < 6);

	if (!dane_OK)
	{
		ilosc = 20;
	}
	ilosc_jednostek_krzyz = ilosc;
}

/// @brief Dodanie zadanej iloœæ jednostek do poszczególnych armii na pocz¹tku symulacji
void Symulacja::dodawanie_jednostek()
{
	srand(time(NULL));
	int los;
	for (int i = 0; i < ilosc_jednostek_pol; i++)
	{
		mapa->dodajJednostkePolsce();
	}

	for (int i = 0; i < ilosc_jednostek_krzyz; i++)
	{
		mapa->dodajJednostkeKrzyzakom();
	}
}

bool Symulacja::koniec_gry()
{
	if (mapa->getarmia_pol().empty())
	{
		graf->wygrana_krzyzacy();
		return 1;
		
	}
	else if (mapa->getarmia_krzyz().empty())
	{
		graf->wygrana_polacy();
		return 1;
	}
	else
	{
		return 0;
	}
}
