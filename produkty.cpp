#include "./Header.h"

int lista_produktow (int promocja = 0) {
    int i;
    int pusta = 0;
    cout << endl << "Lista produktów:" << endl << endl;
    for (i = 1; i < N; i++) {
        if (produkty[i].nazwa != "") {
            pusta = 1;
            cout << i << ". " << produkty[i].nazwa << "   " << "rodzaj: " << produkty[i].typ << "   " << "ilość: " << produkty[i].ilosc << " szt." << "   " << "cena: " << produkty[i].cena << " PLN" << endl;
            if (promocja) {
                if (produkty[i].promocja != 0) {
                    cout << "   " << "cena regularna: " << produkty[i].cena_reg << " PLN";
                }
                cout << "   " << "wysokość rabatu: " << produkty[i].promocja << "%" << endl;
            }
        }
    }
    if (!pusta) {
        cout << "Lista produktów jest pusta." << endl
        << endl << "Naciśnij klawisz enter, aby konynuować" << endl;
        cin.ignore();
        cin.get();
        return 1;
    } else {
        cout << endl << endl;
        return 0;
    }
}

void dodaj_produkt(void) {
    string nazwa;
    int dodaj;
    
    cout << "Podaj nazwę produktu, który chcesz dodać:" << endl;
    cin >> nazwa;
    int i;
    for (i = 1; i < N; i++)
    {
        if (produkty[i].nazwa == nazwa) {
            cout << "Nazwa produktu istnieje już w bazie." << endl
            << "Aktualna ilość '" << produkty[i].nazwa << "' to " << produkty[i].ilosc << "." << endl
            << "Ile produktów dodać?" << endl;
            cin >> dodaj;
            produkty[i].ilosc += dodaj;
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

int edytuj_produkt (void) {
    int id, pom = 0;
    if (lista_produktow()) {
        return 1;
    };
    cout << "Podaj ID produktu, który chcesz edytować: " << endl;
    cin >> id;
    int i;
    for (i = 1; i < N; i++) {
        if (produkty[i].id_produktu == id) {
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
        cout << "Nie znaleziono produktu o podanym ID." << endl;
    }
    return 0;
}

int usun_produkt (void) {
    int id, pom = 0;
    char odp;
    if (lista_produktow()) {
        return 1;
    };
    cout << "Podaj ID produktu, który chcesz usunąć: " << endl;
    cin >> id;
    int i;
    for (i = 1; i < N; i++) {
		if (id == 0) {
			break;
		} else if (produkty[i].id_produktu == id) {
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
			}
			else if (odp == 'n') {
				cout << "Usuwanie anulowane." << endl;
				break;
            } else {
                cout << "Błędna odpowiedź." << endl;
                break;
            }
        }
    }
    if (!pom) {
        cout << "Nie znaleziono produktu o podanym ID." << endl;
    }
    return 0;
}

void promocje (void) {
	float cena;
    int id, pom = 0;
    if (!lista_produktow(1)) {
        cout << "Podaj ID produktu, który chcesz objąć promocją: " << endl;
        cin >> id;
        int i;
        for (i = 1; i < N; i++) {
            if (produkty[i].id_produktu == id) {
                pom = 1;
                cout << "Podaj wartość promocji (np. 15%)";
                cin >> produkty[i].promocja;
                cena = produkty[i].cena_reg - (produkty[i].cena_reg * (produkty[i].promocja / 100.00));
				produkty[i].cena = roundf(cena * 100) / 100;
            }
        }
        if (!pom) {
            cout << "Nie znaleziono produktu o podanym ID." << endl;
        } else {
            lista_produktow(1);
            cout << "Naciśnij klawisz enter, aby konynuować" << endl;
            cin.ignore();
            cin.get();
        }
    }
}

void sprzedaj_produkt(void) {
    char wybor;
    bool sukces = false;
    int ilosc, produkt_id, klient_id, i, indeks = 0;
    
    if (lista_klientow()) {
        return;
    }
    cout << endl;
    
    cout << "Podaj ID klienta, który chce dokonać transakcji:" << endl;
    cin >> klient_id;
    
    for (i = 1; i < N; i++) {
        if (klienci[i].id_klienta == klient_id) {
            indeks = i;
            sukces = true;
            break;
        }
    }
    while (indeks) {
        if (lista_produktow()) {
            return;
        }
        cout << endl;
        cout << "Podaj ID produktu, który chce kupić " << klienci[indeks].nazwa << ":" << endl;
        cin >> produkt_id;
        
        sukces = false;
        for (i = 1; i < N; i++) {
            if (produkty[i].id_produktu == produkt_id) {
                cout << "Ile sztuk produktu '" << produkty[i].nazwa << "' chcesz sprzedac? (stan: " << produkty[i].ilosc << ")" << endl;
                cin >> ilosc;
                if (ilosc <= produkty[i].ilosc) {
                    if (klienci[indeks].rabat) {
                        produkty[i].cena -= ((produkty[i].cena * klienci[indeks].rabat) / 100.00);
                        cout << "Przyznano rabat w wysokości: " << klienci[indeks].rabat << "." << endl << endl;;
                    }
                    float cena = produkty[i].cena * ilosc;
                    klienci[indeks].saldo -= cena;
                    produkty[i].ilosc -= ilosc;
                    sukces = true;
                    cout << "Wartość transakcji to: " << cena << " PLN." << endl << endl;
                    break;
                } else {
                    cout << "Nie posiadamy wystarczającej ilości produktu." << endl;
                }
            }
        }
        if (!sukces) {
			cout << endl <<"Nie znaleziono produktu o ID #" << produkt_id << "' na liście produktów." << endl << endl;
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
