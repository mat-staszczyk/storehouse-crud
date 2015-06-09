#include "./Header.h"

int lista_produktow (int promocja = 0, bool przegladanie = false) {
    int i;
    int pusta = 0;
    int licznik = 0;
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
            if (przegladanie) {
                licznik++;
                if (licznik == 10)
                {
                    licznik = 0;
                    cout << endl << "Naciśnij klawisz enter, aby wyświetlić 10 kolejnych pozycji." << endl;
                    cin.ignore();
                    cin.get();
                }
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
			produkty[i].promocja = 0;
            break;
        }
    }
}

int edytuj_produkt (void) {
    string s_temp;
    int id, pom = 0;
    if (lista_produktow()) {
        return 1;
    };
    cout << "Podaj ID produktu, który chcesz edytować: " << endl;
    cin >> id;
    int i;
    for (i = 1; i < N; i++) {
        if (produkty[i].id_produktu == id) {
            pom = id;
            cout << "Edycja obiektu #" << i << ":" << endl;
            cout << "Podaj nową nazwę produktu lub naciśnij Enter i pozostaw aktualną (" << produkty[i].nazwa << "):" << endl;
            cin.ignore();
            getline(cin,s_temp);
            if (s_temp == "") {
                cout << "(" << produkty[i].nazwa << ")" << endl;
            } else {
                produkty[i].nazwa = s_temp;
				s_temp = "";
            }
            
            cout << "Podaj nowy typ produktu lub naciśnij Enter i pozostaw aktualny (" << produkty[i].typ << "):" << endl;
			getline(cin,s_temp);
			if (s_temp == "") {
				cout << "(" << produkty[i].typ << ")" << endl;
			}
			else {
				produkty[i].typ = s_temp;
			}

            cout << "Podaj nową ilość produktu na stanie lub naciśnij Enter i pozostaw aktualną (" << produkty[i].ilosc << "):" << endl;
			getline(cin, s_temp);
			if (s_temp == "") {
				cout << "(" << produkty[i].ilosc << ")" << endl;
			}
			else {
				produkty[i].ilosc = atof(s_temp.c_str());
			}

            cout << "Podaj nową cenę lub naciśnij Enter i pozostaw aktualną (" << produkty[i].cena << "):" << endl;
			getline(cin, s_temp);
			if (s_temp == "") {
				cout << "(" << produkty[i].cena << ")" << endl;
			}
			else {
				produkty[i].cena = atof(s_temp.c_str());
			}
        }
    }
    if (!pom) {
        cout << "Nie znaleziono produktu o podanym ID." << endl;
	} else {
		cout << endl << "ID: #" << pom << "   " << "nazwa: " << produkty[pom].nazwa << "   " << "typ: " << produkty[pom].typ << "   " << "ilość: " << produkty[pom].ilosc << " szt." << "   " << "cena: " << produkty[pom].cena << " PLN" << endl << endl;
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
    int promocja, id, pom = 0;
    if (!lista_produktow(1)) {

        cout << "Podaj ID produktu, który chcesz objąć promocją: " << endl;
        cin >> id;
		cout << "Podaj wartość promocji (np. 15%)";
		cin >> promocja;

        int i;
        for (i = 1; i < N; i++) {
            if (produkty[i].id_produktu == id) {
                pom = 1;
				produkty[i].promocja = promocja;
                cena = produkty[i].cena_reg - (produkty[i].cena_reg * (produkty[i].promocja / static_cast<float>(100)));
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
    bool sukces = false, err = false;
    int ilosc, produkt_id, klient_id, i, indeks = 0;
    
    if (lista_klientow(false)) {
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

        cout << "Podaj ID produktu, który chce kupić " << klienci[indeks].nazwa << ":" << endl;
        cin >> produkt_id;
        
        sukces = false;
        for (i = 1; i < N; i++) {
            if (produkty[i].id_produktu == produkt_id) {
				cout << "Ile sztuk produktu '" << produkty[i].nazwa << "' chcesz sprzedac? (stan: " << produkty[i].ilosc << ")" << endl;
				cin >> ilosc;
                if (ilosc <= produkty[i].ilosc) {
                    if (klienci[indeks].rabat) {
                        produkty[i].cena -= ((produkty[i].cena * klienci[indeks].rabat) / static_cast<float>(100));
                        cout << "Przyznano rabat w wysokości: " << klienci[indeks].rabat << "." << endl << endl;;
                    }
					float cena = roundf(produkty[i].cena * 100) / 100;
					cena *= ilosc;
                    klienci[indeks].saldo -= cena;
                    produkty[i].ilosc -= ilosc;
                    sukces = true;
                    cout << "Wartość transakcji to: " << cena << " PLN." << endl << endl;
                    break;
				}
				else {
					cout << "Nie posiadamy wystarczającej ilości produktu." << endl << endl;
					err = true;
                }
            }
        }
        if (!sukces && !err) {
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
