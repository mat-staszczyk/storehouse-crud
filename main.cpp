#include <iostream>

using namespace std;

int main(void) {
    int wybor;
    cout << "########################" << endl;
    cout << "### OBSŁUGA MAGAZYNU ###" << endl;
    cout << "########################" << endl << endl;
    cout << "Prosze wybrac jedna z ponizszych opcji:" << endl << endl;
    cout << "1. Wyświetl listę produktów." << endl;
    cout << "2. Dodaj nowy produkt." << endl;
    cout << "3. Zarządzanie promocjami." << endl;
    cout << "4. Edytuj produkty na liście." << endl;
    cout << "5. Usuń produkt z listy." << endl;
    cout << "6. Wyświetl listę klientów." << endl;
    cout << "7. Dodaj nowego klienta." << endl;
    cout << "8. Zarządzanie rabatami." << endl;
    cout << "9. Edytuj listę klientów." << endl;
    cout << "10. Usuń klienta z listy." << endl;
    cout << "11. Przeszukaj bazę." << endl;
    cout << "12. Zakończ." << endl;
    
    while (1)
    {
        cout << "Wybór: ";
        cin >> wybor;
        
        switch (wybor)
        {
            case 1:
                //wczytaj
                break;
            case 2:
                //utworz
                break;
            case 3:
                cout << "test";
                return 0;
        }
    }
    
}
