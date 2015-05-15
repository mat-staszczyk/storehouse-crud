#include <iostream>
#include <string>
#include <stdio.h>

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
        float cena_reg;
        int promocja;
    } produkty[N], ptemp;

    struct Klient
    {
        int id_klienta;
        string nazwa;
        string grupa;
        string nip;
        int rabat;
        float saldo;
    } klienci[N], ktemp;

    void menu() {
        cout << "###########################" << endl;
        cout << "### ZARZĄDZANIE TOWAREM ###" << endl;
        cout << "###########################" << endl << endl;
        cout << "Proszę wybrać jedną z poniższych opcji:" << endl << endl;
        cout << "1. Wyświetl listę produktów." << endl;
        cout << "2. Sprzedaj produkt." << endl;
        cout << "3. Dodaj nowy produkt." << endl;
        cout << "4. Edytuj produkty na liście." << endl;
        cout << "5. Usuń produkt z listy." << endl;
        cout << "6. Zarządzanie promocjami." << endl;
        cout << "7. Wyświetl listę klientów." << endl;
        cout << "8. Dodaj nowego klienta." << endl;
        cout << "9. Edytuj listę klientów." << endl;
        cout << "10. Usuń klienta z listy." << endl;
        cout << "11. Zarządzanie rabatami." << endl;
        cout << "12. Przeszukaj bazę." << endl;
        cout << "13. Zapisz aktualny stan." << endl;
        cout << "14. Wczytaj ostatni stan." << endl;
        cout << "15. Zakończ." << endl << endl;

        cout << "Wybór: ";
    }

    void wczytaj_dane () {
        FILE * produkty_arch;
        FILE * klienci_arch;

        produkty_arch = fopen("produkty.store", "rb");
        klienci_arch = fopen("klienci.store", "rb");

        if (fread(&produkty, sizeof(produkty), N, produkty_arch) &&
            fread(&klienci, sizeof(klienci), N, klienci_arch))
        {
            cout << "Dane wczytane prawidłowo." << endl;
        } else {
            cout << "Brak dostępu do danych." << endl;
        }

        fclose(produkty_arch);
        fclose(klienci_arch);
    }

    int lista_produktow (int promocja=0) {
        int i;
        int pusta = 0;
        cout << endl << "Lista produktów:" << endl << endl;
        for (i = 1; i < N; i++) {
            if (!produkty[i].nazwa.empty()) {
                cout << i << ". " << produkty[i].nazwa << "   " << "rodzaj: " << produkty[i].typ << "   " << "ilość: " << produkty[i].ilosc << " szt." << "   " << "cena: " << produkty[i].cena << " PLN" << endl;
                if (promocja) {
                    if (produkty[i].promocja != 0) {
                        cout << "   " << "cena regularna: " << produkty[i].cena_reg << " PLN";
                    }
                    cout << "   " << "wysokość rabatu: " << produkty[i].promocja << "%" << endl;
                }
                pusta = 1;
            }
        }
        if (!pusta) {
            cout << "Lista produktów jest pusta." << endl << endl;
            return 1;
        } else {
            cout << endl << endl;
            return 0;
        }
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
                cin >> produkty[i].cena_reg;
                produkty[i].cena = produkty[i].cena_reg;
                break;
            }
        }
    }

    int edytuj_produkt () {
        string nazwa;
        int pom = 0;
        if (lista_produktow()) {
            cout << endl;
            return 1;
        };
        cout << "Podaj nazwę produktu, który chcesz edytować: " << endl;
        cin >> nazwa;
        int i;
        for (i = 1; i < N; i++) {
            if (produkty[i].nazwa == nazwa) {
                pom = 1;
                cout << "Edycja obiektu #" << i << ":" << endl;
                cout << "Podaj nową nazwę produktu (aktualna nazwa: " << produkty[i].nazwa << "):" << endl;
                cin >> produkty[i].nazwa;
                cout << "Podaj nowy typ produktu (aktualny typ: " << produkty[i].typ << "):" << endl;
                cin >> produkty[i].typ;
                cout << "Podaj nową ilość produktu na stanie (aktualny stan: " << produkty[i].ilosc << "):" << endl;
                cin >> produkty[i].ilosc;
                cout << "Podaj nową cenę (aktualny cena: " << produkty[i].cena << "):" << endl;
                cin >> produkty[i].cena;
            }
        }
        if (pom) {
            cout << "Nie znaleziono produktu o podanej nazwie." << endl;
        }
        return 0;
    }

    int usun_produkt () {
        string nazwa;
        int pom = 0;
        char odp;
        if (lista_produktow()) {
            cout << endl;
            return 1;
        };
        cout << "Podaj nazwę produktu, który chcesz usunąć: " << endl;
        cin >> nazwa;
        int i;
        for (i = 1; i < N; i++) {
            if (produkty[i].nazwa == nazwa) {
                pom = 1;
                cout << "Czy na pewno chcesz usunąć produkt o nazwie " << produkty[i].nazwa << "? (T/n)" << endl;
                cin >> odp;
                if (odp == 'T') {
                    produkty[i].nazwa = "";
                    produkty[i].id_produktu = 0;
                    produkty[i].cena = 0;
                    produkty[i].ilosc = 0;
                    produkty[i].typ = "";
                    produkty[i].promocja = 0;

                    cout << "Produkt został usunięty." << endl;
                    break;
                } else if (odp == 'n') {
                    cout << "Usuwanie anulowane." << endl;
                    break;
                } else {
                    cout << "Błędna odpowiedź." << endl;
                    break;
                }
            }
        }
        if (!pom) {
            cout << "Nie znaleziono produktu o podanej nazwie." << endl;
        }
        return 0;
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
                    produkty[i].cena = produkty[i].cena_reg - (produkty[i].cena_reg * (produkty[i].promocja / 100.00));
                }
            }
            if (!pom) {
                cout << "Nie znaleziono produktu o podanej nazwie." << endl;
            } else {
                lista_produktow(1);
                cout << "Naciśnij klawisz enter, aby konynuować" << endl;
                cin.ignore();
                cin.get();
            }
        }
    }

    int lista_klientow () {
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
            cout << "Lista klientów jest pusta." << endl;
            return 1;
        } else {
            cout << endl;
            return 0;
        }
    }

    void dodaj_klienta () {
        string nazwa;
        cout << "Podaj nazwę klienta, którego chcesz dodać:" << endl;
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

    int edytuj_klienta () {
        string nazwa;
        int pom = 0;
        if (lista_klientow()) {
            cout << endl;
            return 1;
        }
        cout << "Podaj nazwę klienta, którego chcesz edytować:" << endl;
        cin >> nazwa;
        int i;
        for (i = 1; i < N; i++) {
            if (klienci[i].nazwa == nazwa) {
                pom = 1;
                cout << "Edycja danych klienta o id #" << i << ":" << endl;
                cout << "Podaj nową nazwę klienta (aktualna nazwa: " << klienci[i].nazwa << "):" << endl;
                cin >> klienci[i].nazwa;
                cout << "Podaj nową nazwę grupy (aktualna grupa: " << klienci[i].grupa << "):" << endl;
                cin >> klienci[i].grupa;
                cout << "Podaj nowy nr NIP (aktualny nip: " << klienci[i].nip << "):" << endl;
                cin >> klienci[i].nip;
            }
        }
        if (!pom) {
            cout << "Nie znaleziono klienta o podanej nazwie." << endl << "Naciśnij klawisz enter, aby konynuować" << endl;
            cin.ignore();
            cin.get();
        } else {
            lista_klientow();
            cout << "Naciśnij klawisz enter, aby konynuować" << endl;
            cin.ignore();
            cin.get();
        }
        return 0;
    }

    int usun_klienta () {
        if (lista_klientow()) {
            cout << endl;
            return 1;
        }
        string nazwa;
        int pom = 0;
        char odp;
        lista_klientow();
        cout << "Podaj nazwę klienta, którego chcesz usunąć z bazy: " << endl;
        cin >> nazwa;
        int i;
        for (i = 1; i < N; i++) {
            if (klienci[i].nazwa == nazwa) {
                pom = 1;
                cout << "Czy na pewno chcesz usunąć wpis klienta o nazwie " << klienci[i].nazwa << "? (T/n)" << endl;
                cin >> odp;
                if (odp == 'T') {
                    klienci[i].nazwa = "";
                    klienci[i].grupa = "";
                    klienci[i].nip = "";
                    klienci[i].id_klienta = 0;
                    klienci[i].rabat = 0;
                    klienci[i].saldo = 0;
                    cout << "Wpis klienta został usunięty." << endl;
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
        if (!pom) {
            cout << "Nie znaleziono wpisu o podanej nazwie klienta." << endl;
        }
        return 0;
    }

    void rabaty () {
        string nazwa;
        int pom = 0;
        if (!lista_klientow()) {
            cout << "Podaj nazwę klienta, którego chcesz objąć rabatem: " << endl;
            cin >> nazwa;
            int i;
            for (i = 1; i < N; i++) {
                if (klienci[i].nazwa == nazwa) {
                    pom = 1;
                    cout << "Podaj wysokość rabatu (np. 5%)";
                    cin >> klienci[i].rabat;
                }
            }
            if (!pom) {
                cout << "Nie znaleziono wpisu o podanej nazwie klienta." << endl;
            } else {
                lista_klientow();
                cout << "Naciśnij klawisz enter, aby konynuować" << endl;
                cin.ignore();
                cin.get();
            }
        }
    }

    void szukaj() {
        string fraza;
        int pom = 0;
        cout << "Wyszukaj hasło:" << endl;
        cin >> fraza;
        int i;
        cout << endl << "Wyniki wyszukiwania dla kategorii 'Produkty':" << endl << endl;
        for (i = 1; i < N; i++) {
            if (produkty[i].nazwa == fraza || produkty[i].typ == fraza) {
                pom = 1;
                cout << "ID: #" << i << "   " << "nazwa: " << produkty[i].nazwa << "   " << "typ: " << produkty[i].typ << "   " << "ilość: " << produkty[i].ilosc << " szt." << "   " << "cena: " << produkty[i].cena << " PLN" << "   " << "promocja: " << produkty[i].promocja << "%" << endl << endl;
            }
        }
        if (!pom) {
            cout << "brak wyników" << endl << endl;
        }
        cout << "Wyniki wyszukiwania dla kategorii 'Klienci':" << endl << endl;
        pom = 0;
        for (i = 1; i < N; i++) {
            if (klienci[i].nazwa == fraza || klienci[i].grupa == fraza || klienci[i].nip == fraza) {
                pom = 1;
                cout << "ID: #" << i << "   " << "nazwa: " << klienci[i].nazwa << "   " << "grupa: " << klienci[i].grupa << "   " << "NIP: " << klienci[i].nip << "   " << "saldo: " << klienci[i].saldo << " PLN" << "   " << "rabat: " << klienci[i].rabat << "%" << endl << endl;
            }
        }
        if (!pom) {
            cout << "brak wyników" << endl << endl;
        }
        cout << "Naciśnij klawisz enter, aby konynuować" << endl;
        cin.ignore();
        cin.get();
    }

    void zapisz () {
        FILE *produkty_arch;
        FILE *klienci_arch;
        produkty_arch = fopen("produkty.store", "wb");
        klienci_arch = fopen("klienci.store", "wb");

        if (fwrite(produkty, sizeof(struct Produkt), N, produkty_arch) &&
            fwrite(klienci, sizeof(struct Klient), N, klienci_arch))
        {
            cout << "Zapisywanie zakończone powodzeniem." << endl;
        } else {
            cout << "Brak dostępu do dysku!" << endl;
        }
        fclose(produkty_arch);
        fclose(klienci_arch);
        cout << "Naciśnij klawisz enter, aby konynuować" << endl;
        cin.ignore();
        cin.get();
    }

    void sprzedaj_produkt() {
        string produkt;
        string klient;
        char wybor;
        bool sukces = false;
        int ilosc;
        int i;
        int indeks = 0;

        lista_klientow();
        cout << endl;

        cout << "Podaj nazwę klienta, który chce dokonać transakcji:" << endl;
        cin >> klient;

        for (i = 1; i < N; i++) {
            if (klienci[i].nazwa == klient) {
                indeks = i;
                sukces = true;
                break;
            }
        }



        while (indeks) {
            lista_produktow();
            cout << endl;
            cout << "Podaj nazwę produktu, który chce kupić " << klienci[indeks].nazwa << ":" << endl;
            cin >> produkt;

            sukces = false;
            for (i = 1; i < N; i++) {
                if (produkty[i].nazwa == produkt) {
                    cout << "Ile sztuk produktu '" << produkty[i].nazwa << "' chcesz sprzedac? (stan: " << produkty[i].ilosc << ")" << endl;
                    cin >> ilosc;
                    if (ilosc <= produkty[i].ilosc) {
                        sukces = true;
                        produkty[i].ilosc -= ilosc;
                        klienci[indeks].saldo -= (produkty[i].cena * produkty[i].ilosc);
                        break;
                    }
                }
            }
            if (!sukces) {
                cout << endl <<"Nie znaleziono produktu '" << produkt << "' na liście produktów." << endl << endl;
            }

            cout << "Czy klient chce dokonać kolejnej transakcji? (T/n):" << endl;
            cin >> wybor;

            if (wybor != 'T') break;

        }

        if (!indeks) {
            cout << "Klient o podanej nazwie nie figuruje w bazie." << endl;
        }

        if (!sukces) {
            cout << "Transakcja nieudana." << endl;
        } else {
            cout << "Transakcja zakończona sukcesem." << endl;
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
                cout << "Nacisnij klawisz enter, aby kontyunować." << endl;
                cin.ignore();
                cin.get();
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
                lista_klientow();
                cout << "Nacisnij klawisz enter, aby kontyunować." << endl;
                cin.ignore();
                cin.get();
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
                cout << "Możesz teraz bezpiecznie wyłączyć program." << endl;
                return 0;
            default:
                cout << "Błędny wybór." << endl;
                return 0;
        }
    }

}
