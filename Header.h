#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;

const int N = 100;
extern int wybor;
extern string temp;

struct Produkt
{
    int id_produktu;
    string nazwa;
    string typ;
    float ilosc;
    float cena;
    float cena_reg;
    int promocja;
};

extern Produkt produkty[N];

struct Klient
{
    int id_klienta;
    string nazwa;
    string grupa;
    string nip;
    int rabat;
    float saldo;
};

extern Klient klienci[N];

int lista_klientow (void);
void dodaj_klienta (void);
int edytuj_klienta (void);
int usun_klienta (void);
void rabaty (void);

int lista_produktow (int);
void dodaj_produkt(void);
int edytuj_produkt (void);
int usun_produkt (void);
void promocje (void);
void sprzedaj_produkt(void);

void menu(void);
void menu_produkty(void);
void wczytaj_dane(void);
void zapisz(void);
void wyszukiwanie(void);
