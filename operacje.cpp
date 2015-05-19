#include "./Header.h"

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

void szukaj(void) {
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

void wczytaj_dane(void) {
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

void zapisz(void) {
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

void wyszukiwanie() {
    string fraza;
    cout << "Podaj frazę, której chcesz wyszukać:" << endl;
    cin >> fraza;
    bool znacznik = false, pusta = true;


    cout << endl << "Wyniki wyszukiwania dla kategorii 'Produkty':" << endl << endl;
    int i, j = 0;
    for (i = 0; i < N; i++) {
        while (produkty[i].nazwa[j] != '\0') {
            if (produkty[i].nazwa[j] == fraza[0]) {
                int k = 1;
                while (fraza[k] != '\0') {
                    if (produkty[i].nazwa[j+k] == fraza[k]) {
                        znacznik = true;
                    } else {
                        znacznik = false;
                        break;
                    }
                    k++;
                }
                if (znacznik) {
                    pusta = false;
                    cout << "ID: #" << i << "   " << "nazwa: " << produkty[i].nazwa << "   " << "typ: " << produkty[i].typ << "   " << "ilość: " << produkty[i].ilosc << " szt." << "   " << "cena: " << produkty[i].cena << " PLN" << "   " << "promocja: " << produkty[i].promocja << "%" << endl << endl;
                }
            }
            j++;
        }
    }
    for (i = 0; i < N; i++) {
        j = 0;
        while (produkty[i].typ[j] != '\0') {
            if (produkty[i].typ[j] == fraza[0]) {
                int k = 1;
                while (fraza[k] != '\0') {
                    if (produkty[i].typ[j+k] == fraza[k]) {
                        znacznik = true;
                    } else {
                        znacznik = false;
                        break;
                    }
                    k++;
                }
                if (znacznik) {
                    pusta = false;
                    cout << "ID: #" << i << "   " << "nazwa: " << produkty[i].nazwa << "   " << "typ: " << produkty[i].typ << "   " << "ilość: " << produkty[i].ilosc << " szt." << "   " << "cena: " << produkty[i].cena << " PLN" << "   " << "promocja: " << produkty[i].promocja << "%" << endl << endl;
                }
            }
            j++;
        }
    }

    if (pusta) {
        cout << "brak wyników" << endl << endl;
    }

    cout << endl << "Wyniki wyszukiwania dla kategorii 'Klienci':" << endl << endl;

    for (i = 0; i < N; i++) {
        j = 0;
        while (klienci[i].nazwa[j] != '\0') {
            if (klienci[i].nazwa[j] == fraza[0]) {
                int k = 1;
                while (fraza[k] != '\0') {
                    if (klienci[i].nazwa[j+k] == fraza[k]) {
                        znacznik = true;
                    } else {
                        znacznik = false;
                        break;
                    }
                    k++;
                }
                if (znacznik) {
                    pusta = false;
                    cout << "ID: #" << i << "   " << "nazwa: " << klienci[i].nazwa << "   " << "grupa: " << klienci[i].grupa << "   " << "NIP: " << klienci[i].nip << "   " << "saldo: " << klienci[i].saldo << " PLN" << "   " << "rabat: " << klienci[i].rabat << "%" << endl << endl;
                }
            }
            j++;
        }
    }

    for (i = 0; i < N; i++) {
        j = 0;
        while (klienci[i].grupa[j] != '\0') {
            if (klienci[i].grupa[j] == fraza[0]) {
                int k = 1;
                while (fraza[k] != '\0') {
                    if (klienci[i].grupa[j+k] == fraza[k]) {
                        znacznik = true;
                    } else {
                        znacznik = false;
                        break;
                    }
                    k++;
                }
                if (znacznik) {
                    pusta = false;
                    cout << "ID: #" << i << "   " << "nazwa: " << klienci[i].nazwa << "   " << "grupa: " << klienci[i].grupa << "   " << "NIP: " << klienci[i].nip << "   " << "saldo: " << klienci[i].saldo << " PLN" << "   " << "rabat: " << klienci[i].rabat << "%" << endl << endl;
                }
            }
            j++;
        }
    }

    for (i = 0; i < N; i++) {
        j = 0;
        while (klienci[i].nip[j] != '\0') {
            if (klienci[i].nip[j] == fraza[0]) {
                int k = 1;
                while (fraza[k] != '\0') {
                    if (klienci[i].nip[j+k] == fraza[k]) {
                        znacznik = true;
                    } else {
                        znacznik = false;
                        break;
                    }
                    k++;
                }
                if (znacznik) {
                    pusta = false;
                    cout << "ID: #" << i << "   " << "nazwa: " << klienci[i].nazwa << "   " << "grupa: " << klienci[i].grupa << "   " << "NIP: " << klienci[i].nip << "   " << "saldo: " << klienci[i].saldo << " PLN" << "   " << "rabat: " << klienci[i].rabat << "%" << endl << endl;
                }
            }
            j++;
        }
    }

    if (pusta) {
        cout << "brak wyników" << endl << endl;
    }
    cout << "Naciśnij klawisz enter, aby konynuować" << endl;
    cin.ignore();
    cin.get();

}
