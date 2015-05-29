#include "./Header.h"

int wybor;
string temp;
Produkt produkty[N];
Klient klienci[N];

int main(void) {

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
                dodaj_produkt();
                break;
            case 4:
                edytuj_produkt();
                break;
            case 5:
                usun_produkt();
                break;
            case 6:
                promocje();
                break;
            case 7:
                if (!lista_klientow()) {
                    cout << "Nacisnij klawisz enter, aby kontynuować." << endl;
                    cin.ignore();
                    cin.get();
                }
                break;
            case 8:
                dodaj_klienta();
                break;
            case 9:
                edytuj_klienta();
                break;
            case 10:
                usun_klienta();
                break;
            case 11:
                rabaty();
                break;
            case 12:
                wyszukiwanie();
                break;
            case 13:
                zapisz();
                break;
            case 14:
                wczytaj_dane();
                break;
            case 15:
                cout << "Działanie programu zostało zakończone." << endl;
                return 0;
            default:
                cout << "Błędny wybór." << endl;
                break;
        }
    }

}
