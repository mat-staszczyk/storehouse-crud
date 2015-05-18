#include "./Header.h"

int wybor;
Produkt produkty[N];
Klient klienci[N];

int main(void) {

    while (1)
    {
        menu ();
        cin >> wybor;

        switch (wybor)
        {
            case 1:
                if (!lista_produktow(0)) {
                    cout << "Naciśnij klawisz enter, aby kontynuować" << endl;
                    cin.ignore();
                    cin.get();
                }
                break;
            case 2:
                sprzedaj_produkt();
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
                szukaj();
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
