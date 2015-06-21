#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;

extern int N;
extern int N1;
extern int N2;
extern int p_len;
extern int k_len;
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

struct Klient
{
    int id_klienta;
    string nazwa;
    string grupa;
    string nip;
    int rabat;
    float saldo;
};

extern Klient * klienci;
extern Produkt * produkty;

void sprzedaj_produkt(void);

int lista_klientow (bool);
void dodaj_klienta (void);
int edytuj_klienta (void);
int usun_klienta (void);

int lista_produktow (int, bool);
void dodaj_produkt(void);
int edytuj_produkt (void);
int usun_produkt (void);

void rabaty(void);
void promocje(void);

void menu(void);
void menu_produkty(void);
void menu_klienci(void);
void menu_rabaty(void);

void wczytaj_dane(void);
void zapisz(void);
void wyszukiwanie(void);
