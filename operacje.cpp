#include "./Header.h"

int p_len = 1;
int k_len = 1;

void menu() {
	cout << "###########################" << endl
		 << "### ZARZĄDZANIE TOWAREM ###" << endl
		 << "###########################" << endl << endl
		 << "Proszę wybrać jedną z poniższych opcji:" << endl << endl
		 << "1. Sprzedaż." << endl
		 << "2. Zarządzaj bazą produktów." << endl
		 << "3. Zarządzaj bazą klientów." << endl
		 << "4. Rabaty i promocje." << endl
		 << "5. Przeszukaj bazę." << endl
		 << "6. Zapisz aktualny stan." << endl
		 << "7. Wczytaj ostatni stan." << endl
		 << "8. Zakończ." << endl << endl

		 << "Wybór: ";
}

void menu_produkty() {
	int wybor;
	string temp;
	bool go = 1;
	while (go) {
		cout << "#####################" << endl
			<< "### MENU PRODUKTY ###" << endl
			<< "#####################" << endl << endl
			<< "Proszę wybrać jedną z poniższych opcji:" << endl << endl
			<< "1. Wyświetl listę produktów." << endl
			<< "2. Dodaj nowy produkt." << endl
			<< "3. Edytuj produkty na liście." << endl
			<< "4. Usuń produkt z listy." << endl
			<< "5. Powrót do głównego menu." << endl << endl
			<< "Wybór: ";
			cin >> temp;
			wybor = atoi(temp.c_str());

			switch (wybor) {
			case 1:
				if (!lista_produktow(0, true)) {
					cout << "Naciśnij klawisz enter, aby kontynuować." << endl << flush;
                    cin.ignore();
					cin.get();
				}
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
				go = false;
				break;
			default:
				cout << "Błędny wybór.";
				break;

			}
	}
}

void menu_klienci() {
	int wybor;
	string temp;
	bool go = 1;
	while (go) {
		cout << "####################" << endl
			<< "### MENU KLIENCI ###" << endl
			<< "####################" << endl << endl
			<< "Proszę wybrać jedną z poniższych opcji:" << endl << endl
			<< "1. Wyświetl listę klientów." << endl
			<< "2. Dodaj nowego klienta." << endl
			<< "3. Edytuj listę klientów." << endl
			<< "4. Usuń klienta z listy." << endl
			<< "5. Powrót do głównego menu." << endl << endl
			<< "Wybór: ";
		cin >> temp;
		wybor = atoi(temp.c_str());

		switch (wybor) {
		case 1:
			if (!lista_klientow(true)) {
                cout << "Nacisnij klawisz enter, aby kontynuować." << endl << flush;
                cin.ignore();
				cin.get();
			}
			break;
		case 2:
			dodaj_klienta();
			break;
		case 3:
			edytuj_klienta();
			break;
		case 4:
			usun_klienta();
			break;
		case 5:
			go = false;
			break;
		default:
			cout << "Błędny wybór.";
			break;

		}
	}
}

void menu_rabaty() {
	int wybor;
	string temp;
	bool go = 1;
	while (go) {
		cout << "##############################" << endl
			<< "### MENU PROMOCJE I RABATY ###" << endl
			<< "##############################" << endl << endl
			<< "Proszę wybrać jedną z poniższych opcji:" << endl << endl
			<< "1. Zarządzanie promocjami produktów." << endl
			<< "2. Zarządzanie rabatami klientów." << endl
			<< "3. Powrót do głównego menu." << endl << endl
			<< "Wybór: ";
		cin >> temp;
		wybor = atoi(temp.c_str());

		switch (wybor) {
		case 1:
			promocje();
			break;
		case 2:
			rabaty();
			break;
		case 3:
			go = false;
			break;
		default:
			cout << "Błędny wybór.";
			break;

		}
	}
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
	}
	else {
        cout << "Brak dostępu do danych!" << endl << endl;
	}
	fclose(produkty_arch);
	fclose(klienci_arch);
}

void wczytaj_dane(void) {
	FILE * produkty_arch;
	FILE * klienci_arch;

	produkty_arch = fopen("produkty.store", "rb");
	klienci_arch = fopen("klienci.store", "rb");

	// use while to check if file exists

	if (fread(produkty, sizeof(Produkt), N, produkty_arch) &&
		fread(klienci, sizeof(Klient), N, klienci_arch))
	{
		cout << "Dane wczytane prawidłowo." << endl << endl;
	}
	else {
		cout << "Brak dostępu do danych." << endl;
	}

	fclose(produkty_arch);
	fclose(klienci_arch);
}

void wyszukiwanie() {
	string fraza;
	cout << "Podaj frazę, której chcesz wyszukać:" << endl;
	cin >> fraza;
	bool pusta = true;

    
    cout << endl << "Wyniki wyszukiwania dla kategorii 'Produkty':" << endl << endl;
    for (int i = 0; i < N; i++)
    {
        if (produkty[i].nazwa.find(fraza) != string::npos) {
            pusta = false;
            cout << "ID: #" << i << "   " << "nazwa: " << produkty[i].nazwa << "   " << "typ: " << produkty[i].typ << "   " << "ilość: " << produkty[i].ilosc << " szt." << "   " << "cena: " << produkty[i].cena << " PLN" << "   " << "promocja: " << produkty[i].promocja << "%" << endl << endl;
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        if (produkty[i].typ.find(fraza) != string::npos) {
            pusta = false;
            cout << "ID: #" << i << "   " << "nazwa: " << produkty[i].nazwa << "   " << "typ: " << produkty[i].typ << "   " << "ilość: " << produkty[i].ilosc << " szt." << "   " << "cena: " << produkty[i].cena << " PLN" << "   " << "promocja: " << produkty[i].promocja << "%" << endl << endl;
        }
    }
    
    if (pusta) {
        cout << "Brak wyników." << endl << endl;
    }
    
    pusta = true;
    cout << endl << "Wyniki wyszukiwania dla kategorii 'Klienci':" << endl << endl;
    
    for (int i = 0; i < N; i++)
    {
        if (klienci[i].nazwa.find(fraza) != string::npos) {
            pusta = false;
                cout << "ID: #" << i << "   " << "nazwa: " << klienci[i].nazwa << "   " << "grupa: " << klienci[i].grupa << "   " << "NIP: " << klienci[i].nip << "   " << "saldo: " << klienci[i].saldo << " PLN" << "   " << "rabat: " << klienci[i].rabat << "%" << endl << endl;
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        if (klienci[i].grupa.find(fraza) != string::npos) {
            pusta = false;
            cout << "ID: #" << i << "   " << "nazwa: " << klienci[i].nazwa << "   " << "grupa: " << klienci[i].grupa << "   " << "NIP: " << klienci[i].nip << "   " << "saldo: " << klienci[i].saldo << " PLN" << "   " << "rabat: " << klienci[i].rabat << "%" << endl << endl;
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        if (klienci[i].nip.find(fraza) != string::npos) {
            pusta = false;
            cout << "ID: #" << i << "   " << "nazwa: " << klienci[i].nazwa << "   " << "grupa: " << klienci[i].grupa << "   " << "NIP: " << klienci[i].nip << "   " << "saldo: " << klienci[i].saldo << " PLN" << "   " << "rabat: " << klienci[i].rabat << "%" << endl << endl;
        }
    }
    
    if (pusta) {
        cout << "Brak wyników." << endl << endl;
    }
    
	cout << "Naciśnij klawisz enter, aby konynuować." << endl;
	cin.ignore();
	cin.get();

}