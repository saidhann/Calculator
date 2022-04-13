#include "Struktura.h"
#include <stdlib.h>

void dodajelement(stos* liczby, int wartosc) // dodawanie elementow na stos
{
	element* temp = malloc(sizeof(element));
	temp->wartosc = wartosc;
	temp->nastepny = liczby->napierwszy;
	liczby->napierwszy = temp;
	liczby->rozmiar++;
}
int usunelement(stos* liczby) // usuwanie elementow ze stosu
{
	void* temp = liczby->napierwszy;
	int wartosc = liczby->napierwszy->wartosc;
	liczby->napierwszy = liczby->napierwszy->nastepny;
	free(temp);
	liczby->rozmiar--;
	return wartosc;
}
void inicjacja(stos* liczby, element* pierwszy) // inicjowanie stosu
{
	liczby->napierwszy = pierwszy;
	liczby->rozmiar = 0;
}