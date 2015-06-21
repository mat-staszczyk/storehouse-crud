#include "./Header.h"

int N = 100;
int N1, N2;
int wybor;
string temp;

Klient * klienci = new Klient [N];
Produkt * produkty = new Produkt [N];

int main(void) {
    wczytaj_dane();
    while (1)
    {
        menu ();
        cin >> temp;
        wybor = atoi(temp.c_str());

        switch (wybor)
        {
            case 1:
				sprzedaj_produkt();
                break;
            case 2:
				menu_produkty();
                break;
            case 3:
				menu_klienci();
                break;
            case 4:
				menu_rabaty();
                break;
            case 5:
                wyszukiwanie();
                break;
            case 6:
                zapisz();
                break;
            case 7:
                wczytaj_dane();
                break;
            case 8:
                zapisz();
                cout << "Działanie programu zostało zakończone." << endl;
				delete[] klienci;
				delete[] produkty;
                return EXIT_SUCCESS;
            default:
                cout << "Błędny wybór." << endl;
                break;
        }
    }
    return EXIT_FAILURE;
}
