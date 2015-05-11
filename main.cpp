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
        string nip;
        int rabat;
        unsigned int saldo;
    } klienci[N];

    void menu() {
        cout << "########################" << endl;
        cout << "### OBSŁUGA MAGAZYNU ###" << endl;
        cout << "########################" << endl << endl;
        cout << "Proszę wybrać jedną z poniższych opcji:" << endl << endl;
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
        string nazwa;

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

    int lista_produktow (int promocja=0) {
        int i;
        int pusta = 0;
        float cena_promocyjna;
        cout << endl << "Lista produktów:" << endl << endl;
        for (i = 1; i < N; i++) {
            if (!produkty[i].nazwa.empty()) {
                cout << i << ". " << produkty[i].nazwa << "   " << "ilość: " << produkty[i].ilosc << " szt." << "   " << "cena: " << produkty[i].cena << " PLN" << endl;
                if (promocja) {
                    if (produkty[i].promocja != 0) {
                        cena_promocyjna = produkty[i].cena - (produkty[i].cena * (produkty[i].promocja / 100.00));
                        cout << "   " << "cena promocyjna: " << cena_promocyjna << " PLN";
                    }
                    cout << "   " << "wielkość rabatu: " << produkty[i].promocja << "%" << endl;
                }
                pusta = 1;
            }
        }
        if (!pusta) {
            cout << "Lista klientów jest pusta." << endl << endl << "Naciśnij Enter aby kontyunować" << endl;
            cin.ignore();
            cin.get();
            return 1;
        } else {
            cout << endl << endl << "Naciśnij Enter aby kontyunować" << endl;
            cin.ignore();
            cin.get();
            return 0;
        }
    }

    void edytuj_produkt () {
        string nazwa;
        lista_produktow();
        cout << "Podaj nazwę produktu, który chcesz edytować: " << endl;
        cin >> nazwa;
        int i;
        for (i = 1; i < N; i++) {
            if (produkty[i].nazwa == nazwa) {
                cout << "Edycja obiektu #" << i << ":" << endl;
                cout << "Podaj nową nazwę produktu (aktualna nazwa: " << produkty[i].nazwa << " ):" << endl;
                cin >> produkty[i].nazwa;
                cout << "Podaj nowy typ produktu (aktualny typ: " << produkty[i].typ << " ):" << endl;
                cin >> produkty[i].typ;
                cout << "Podaj nową ilość produktu na stanie (aktualny stan: " << produkty[i].ilosc << " ):" << endl;
                cin >> produkty[i].ilosc;
                cout << "Podaj nową cenę (aktualny cena: " << produkty[i].cena << " ):" << endl;
                cin >> produkty[i].cena;
            }
        }
        cout << "Nie znaleziono produktu o podanej nazwie." << endl;
    }

    void usun_produkt () {
        string nazwa;
        char odp;
        lista_produktow();
        cout << "Podaj nazwę produktu, który chcesz usunąć: " << endl;
        cin >> nazwa;
        int i;
        for (i = 1; i < N; i++) {
            if (produkty[i].nazwa == nazwa) {
                cout << "Czy na pewno chcesz usunąć produkt o nazwie " << produkty[i].nazwa << "? (T/n)" << endl;
                cin >> odp;
                if (odp == 'T') {
                    produkty[i].nazwa = "";
                    produkty[i].id_produktu = 0;
                    produkty[i].cena = 0;
                    produkty[i].ilosc = 0;
                    produkty[i].typ = "";
                    produkty[i].promocja = 0;

                    cout << "Produkt został usunięty.";
                    break;
                } else if (odp == 'n') {
                    cout << "Usuwanie anulowane.";
                    break;
                } else {
                    cout << "Błędna odpowiedź.";
                    break;
                }
            }
        }
        cout << "Nie znaleziono produktu o podanej nazwie." << endl;
    }

    void promocje () {
        string nazwa;
        int pom = 0;
        if (!lista_produktow(1)) {
            cout << "Podaj nazwę produktu, który chcesz objąć promocją: " << endl;
            cin >> nazwa;
            int i;
            for (i = 1; i < N; i++) {
                if (produkty[i].nazwa == nazwa) {
                    pom = 1;
                    cout << "Podaj wartość promocji (np. 15%)";
                    cin >> produkty[i].promocja;
                }
            }
            if (!pom) {
                cout << "Nie znaleziono produktu o podanej nazwie." << endl;
            } else {
                lista_produktow(1);
                cout << endl;
                cin.get();
            }
        }
    }

    void lista_klientow () {
        int i;
        int pusta = 0;
        cout << endl << "Lista klientów:" << endl << endl;
        for (i = 1; i < N; i++) {
            if (!klienci[i].nazwa.empty()) {
                cout << i << ". " << klienci[i].nazwa << "   " << "grupa: " << klienci[i].grupa << "   " << "NIP: " << klienci[i].nip << "   " << "saldo: " << klienci[i].saldo << " PLN" << "   " << "rabat: " << klienci[i].rabat << "%" << endl;
                pusta = 1;
            }
        }
        if (!pusta) {
            cout << "Lista klientów jest pusta." << endl << endl << "Naciśnij Enter aby kontyunować" << endl;
            cin.ignore();
            cin.get();
        } else {
            cout << endl << "Naciśnij Enter aby kontyunować" << endl;
            cin.ignore();
            cin.get();
        }
    }

    void dodaj_klienta () {
        string nazwa;

        cout << "Podaj nazwę klienta, który chcesz dodać:" << endl;
        cin >> nazwa;
        int i;
        for (i = 1; i < N; i++)
        {
            if (klienci[i].nazwa == nazwa) {
                cout << "Nazwa produktu istnieje już w bazie." << endl;
                break;
            } else if (produkty[i].nazwa.empty()) {
                klienci[i].nazwa = nazwa;
                klienci[i].id_klienta = i;
                cout << "Podaj grupę klienta" << endl;;
                cin >> klienci[i].grupa;
                cout << "Podaj NIP klienta:" << endl;
                cin >> klienci[i].nip;
                break;
            }
        }
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
            case 3:
                edytuj_produkt();
                break;
            case 4:
                usun_produkt();
                break;
            case 5:
                promocje();
                break;
            case 6:
                lista_klientow();
                break;
            case 7:
                dodaj_klienta();
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
