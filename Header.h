#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

const int N = 100;
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
} produkty[N];

struct Klient
{
    int id_klienta;
    string nazwa;
    string grupa;
    string nip;
    int rabat;
    float saldo;
} klienci[N];

void menu();
void szukaj();
void wczytaj_dane();
void zapisz ();

extern int lista_produktow (int);
void dodaj_produkt();
int edytuj_produkt();
int usun_produkt();
void promocje();
void sprzedaj_produkt();

int lista_klientow ();
void dodaj_klienta();
int edytuj_klienta();
int usun_klienta();
void rabaty();
