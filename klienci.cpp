#include "./Header.h"

int lista_klientow (bool przegladanie = false) {
    int licznik = 0;
    int i;
    int pusta = 0;
    cout << endl << "Lista klientów:" << endl << endl;
    for (i = 1; i < N; i++) {
        if (!klienci[i].nazwa.empty())
        {
            if (przegladanie)
            {
                licznik++;
                if (licznik > 10)
                {
                    licznik = 0;
                    cout << endl << "Naciśnij klawisz enter, aby wyświetlić 10 kolejnych pozycji." << endl;
                    cin.ignore();
                    cin.get();
                }
            }
            cout << i << ". " << klienci[i].nazwa << "   " << "grupa: " << klienci[i].grupa << "   " << "NIP: " << klienci[i].nip << "   " << "saldo: " << klienci[i].saldo << " PLN" << "   " << "rabat: " << klienci[i].rabat << "%" << endl;
            pusta = 1;
        }
    }
    if (!pusta) {
        cout << "Lista klientów jest pusta." << endl
        << endl << "Naciśnij klawisz enter, aby konynuować" << endl;
        cin.ignore();
        cin.get();
        return 1;
    } else {
        cout << endl;
        return 0;
    }
}

void dodaj_klienta (void) {
    string nazwa, grupa, nip, temp = "";
    bool nip_err = true;
    cout << "Podaj nazwę klienta, którego chcesz dodać:" << endl;
    cin.ignore();
    fflush( stdin );
    getline(cin, nazwa);
	cout << "Podaj grupę klienta" << endl;
    fflush( stdin );
	getline(cin, grupa);
    while (nip_err)
    {
        cout << "Podaj NIP klienta:" << endl;
        fflush( stdin );
        getline(cin, nip);
        // Sprawdzenie poprawności nr NIP
        int nip_len = (int) nip.length();
        if (nip_len == 10) {
            for (int i = 0; i < 10; i++)
            {
                if (i == 3 || i == 6 || i == 8) {
                    temp.append("-");
                }
                temp.append(nip, i, 1);
            }
            nip = temp;
            nip_err = false;
        } else if (nip_len != 13) {
            // błędna długość
            cout << "Błędna długość" << endl;;
    }
    // test poprawności formatu
    }
    int i;
    for (i = 1; i < N; i++)
    {
        if (klienci[i].nazwa == nazwa) {
            cout << "Nazwa klienta istnieje już w bazie." << endl;
            break;
        } else if (klienci[i].nazwa.empty()) {
            klienci[i].nazwa = nazwa;
            klienci[i].id_klienta = i;
            klienci[i].grupa = grupa;
            klienci[i].nip = nip;
            klienci[i].rabat = 0;
            klienci[i].saldo = 0;
            break;
        }
    }
}

int zarzadzanie_srodkami (void) {
	int id;
    int wybor;
    int kwota = 0;
    bool problem = true;
    string temp;
	if (lista_klientow()) {
		return 1;
	}
	cout << "Podaj ID klienta, dla którego ma być przeprowadzona operacja:" << endl;
	cin >> id;
	for (int i = 1; i < N; i++) {
		if (klienci[i].id_klienta == id) {
            while (problem)
            {
                cout << endl << "Proszę wybrać rodzaj operacji, która ma zostać wykonana dla klienta o nazwie \"" << klienci[i].nazwa << "\": " << endl << endl <<
                "1. Dodawanie środków." << endl <<
                "2. Odejmowanie środków." << endl <<
                "3. Zerowanie stanu konta." << endl <<
                "4. Powrót." << endl;
                cin >> temp;
                wybor = atoi(temp.c_str());

                switch (wybor)
                {
                    case 1:
                        cout << endl << "Podaj kwotę, o którą ma zostać zwiększony stan konta:" << endl;
                        cin >> kwota;
                        if (kwota > 0) {
                            klienci[i].saldo += kwota;
                            cout << "Aktualny stan środków klienta " << klienci[i].nazwa << " to: " << klienci[i].saldo << " PLN." << endl;
                        } else {
                            cout << "Podano błędną kwotę." << endl;
                        }
                        problem = false;
                        break;
                    case 2:
                        cout << endl << "Podaj kwotę, o którą ma zostać zmniejszony stan konta:" << endl;
                        cin >> kwota;
                        if (kwota > 0) {
                            klienci[i].saldo -= kwota;
                            cout << "Aktualny stan środków klienta " << klienci[i].nazwa << " to: " << klienci[i].saldo << " PLN." << endl;
                        } else {
                            cout << "Podano błędną kwotę." << endl;
                        }
                        problem = false;
                        break;
                    case 3:
                        klienci[i].saldo = 0;
                        problem = false;
                        break;
                    default:
                        cout << endl << "Błąd wyboru operacji. Proszę spróbować ponownie." << endl;
                        break;
                }
            }
		}
	}
    return 0;
}

int edytuj_klienta (void) {
	string s_temp;
	int id;
    int pom = 0;
    if (lista_klientow()) {
        return 1;
    }
    cout << "Podaj ID klienta, którego chcesz edytować:" << endl;
    cin >> id;
    int i;
    for (i = 1; i < N; i++) {
        if (klienci[i].id_klienta == id) {
            pom = i;
            cout << "Edycja danych klienta #" << i << " " << klienci[i].nazwa << ":" << endl;
			cout << "Podaj nową nazwę klienta lub naciśnij Enter i pozostaw aktualną (" << klienci[i].nazwa << "):" << endl;
			cin.ignore();
            fflush( stdin );
			getline(cin, s_temp);
			if (s_temp == "") {
				cout << "(" << klienci[i].nazwa << ")" << endl;
			}
			else {
				klienci[i].nazwa = s_temp;
				s_temp = "";
			}

            cout << "Podaj nową nazwę grupy lub naciśnij klawisz Enter i pozostaw aktualną (" << klienci[i].grupa << "):" << endl;
            fflush( stdin );
			getline(cin, s_temp);
			if (s_temp == "") {
				cout << "(" << klienci[i].grupa << ")" << endl;
			}
			else {
				klienci[i].grupa = s_temp;
				s_temp = "";
			}

            cout << "Podaj nowy nr NIP lub naciśnij klawisz Enter i pozostaw aktualny (" << klienci[i].nip << "):" << endl;
            fflush( stdin );
			getline(cin, s_temp);
			if (s_temp == "") {
				cout << "(" << klienci[i].nip << ")" << endl;
			}
			else {
				klienci[i].nip = atof(s_temp.c_str());
			}
        }
    }
    if (!pom) {
        cout << "Nie znaleziono klienta o podanym ID." << endl << "Naciśnij klawisz Enter, aby konynuować" << endl;
        cin.ignore();
        cin.get();
    } else {
		cout << pom << ". " << klienci[pom].nazwa << "   " << "grupa: " << klienci[pom].grupa << "   " << "NIP: " << klienci[pom].nip << endl;
    }
    return 0;
}

int usun_klienta (void) {
    if (lista_klientow()) {
        return 1;
    }
    int id;
    int pom = 0;
    char odp;
    cout << "Podaj ID, którego chcesz usunąć z bazy: " << endl;
    cin >> id;
    int i;
    for (i = 1; i < N; i++) {
        if (klienci[i].id_klienta == id) {
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

				// Uporządkowanie rozmiaru listy po usunięciu pozycji
				int j = i;
				while (j < N) {
                    // Zmiana pozycji bez naruszenia numeru id
					*(klienci + j++) = *(klienci + j);
				}

                cout << "Wpis klienta został usunięty." << endl;
                break;
            } else {
                cout << "Usuwanie anulowane.";
                break;
            }
        }
    }
    if (!pom) {
        cout << "Nie znaleziono wpisu o podanej nazwie klienta." << endl;
    }
    return 0;
}

void rabaty (void) {
    int wybor, id, pom = 0;
	string grupa, temp;
	int rabat;
	cout << "Zmień wysokość rabatu:" << endl <<
			"1. Pojedynczego klienta" << endl <<
			"2. Grupy klinetów" << endl;
	cin >> temp;
	wybor = atoi(temp.c_str());

	switch (wybor) {
	case 1:
		if (!lista_klientow()) {
			cout << "Podaj ID klienta, którego rabat ma zostać zmodyfikowany:" << endl;
			cin >> id;
			cout << "Podaj wysokość rabatu (np. 5%):" << endl;
			cin >> rabat;
			int i;
			for (i = 1; i < N; i++) {
				if (klienci[i].id_klienta == id) {
					pom = 1;
					cout << "Podaj procentową wielkość rabatu (np. 5):" << endl;
					klienci[i].rabat = rabat;
				}
			}
			if (!pom) {
				cout << "Nie znaleziono wpisu o podanym ID klienta." << endl;
			}
			else {
				lista_klientow();
				cout << "Naciśnij klawisz Enter, aby konynuować." << endl;
				cin.ignore();
				cin.get();
			}
		}
		break;
	case 2:
		if (!lista_klientow()) {
			cout << "Podaj nazwę grupy, której ma zostać przyznany rabat:" << endl;
			cin >> grupa;
			cout << "Podaj wysokość rabatu (np. 5%):" << endl;
			cin >> rabat;
			int i;
			for (i = 1; i < N; i++) {
				if (klienci[i].grupa == grupa) {
					pom = 1;
					klienci[i].rabat = rabat;
				}
			}
			if (!pom) {
				cout << "Nie znaleziono grupy o podanej nazwie." << endl;
			}
			else {
				lista_klientow();
				cout << "Naciśnij klawisz Enter, aby konynuować." << endl;
				cin.ignore();
				cin.get();
			}
		}
		break;
	default:
		cout << "Błędny wybór." << endl;
		break;
	}
}
