#include <iostream>
#include <string>

using namespace std;

    const int N = 100; // wielkość katalogu
    int wybor;

    struct Produkt
    {
        int id_produktu;
        string nazwa;
        string typ;
        int ilosc;
        float cena;
        int promocja;
    } produkty[N];

    struct Klient
    {
        int id_klienta;
        string nazwa;
        string grupa;
        int rabat;
    } klienci[N];

    void menu() {
        cout << "########################" << endl;
        cout << "### OBSŁUGA MAGAZYNU ###" << endl;
        cout << "########################" << endl << endl;
        cout << "Prosze wybrac jedna z ponizszych opcji:" << endl << endl;
        cout << "1. Wyświetl listę produktów." << endl;
        cout << "2. Dodaj nowy produkt." << endl;
        cout << "3. Edytuj produkty na liście." << endl;
        cout << "4. Usuń produkt z listy." << endl;
        cout << "5. Zarządzanie promocjami." << endl;
        cout << "6. Wyświetl listę klientów." << endl;
        cout << "7. Dodaj nowego klienta." << endl;
        cout << "9. Edytuj listę klientów." << endl;
        cout << "10. Usuń klienta z listy." << endl;
        cout << "11. Zarządzanie rabatami." << endl;
        cout << "12. Przeszukaj bazę." << endl;
        cout << "13. Zapisz i zakończ." << endl;

        cout << "Wybór: ";
    }

    void dodaj_produkt() {
        string nazwa, typ;
        int ilosc, cena, promocja;

        cout << "Podaj nazwę produktu, który chcesz dodać:" << endl;
        cin >> nazwa;
        int i;
        for (i = 1; i < N; i++)
        {
            if (produkty[i].nazwa == nazwa) {
                cout << "Nazwa produktu istnieje już w bazie." << endl;
                break;
            } else if (produkty[i].nazwa.empty()) {
                produkty[i].nazwa = nazwa;
                produkty[i].id_produktu = i;
                cout << "Podaj typ produktu:" << endl;;
                cin >> produkty[i].typ;
                cout << "Podaj ilość produktów na stanie:" << endl;
                cin >> produkty[i].ilosc;
                cout << "Podaj cenę jednego produktu:" << endl;
                cin >> produkty[i].cena;
                break;
            }
        }
    }

    void lista_produktow () {
        int i;
        cout << endl << "Lista produktów:" << endl << endl;
        for (i = 1; i < N; i++) {
            if (!produkty[i].nazwa.empty()) {
                cout << i << ". " << produkty[i].nazwa << "   " << "Ilość: " << produkty[i].ilosc << " szt." << "   " << "Cena: " << produkty[i].cena << " PLN" << endl;
            }
        }
        /*
        cout << produkty[0].nazwa << endl;
        cout << produkty[0].typ << endl;
        cout << produkty[0].id_produktu << endl;
        cout << produkty[0].ilosc << endl;
        cout << produkty[0].cena << endl;
        */
        cout << endl;
    }

int main(void) {

    while (1)
    {
        menu ();
        cin >> wybor;

        switch (wybor)
        {
            case 1:
                lista_produktow();
                break;
            case 2:
                dodaj_produkt();
                break;
            case 13:
                cout << "Możesz teraz bezpiecznie wyłączyć program." << endl;
                return 0;
            default:
                cout << "Błędny wybór." << endl;
                return 0;
        }
    }

}
