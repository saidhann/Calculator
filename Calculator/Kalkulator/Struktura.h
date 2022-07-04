#pragma once

struct element;
// obiekt elementu stosu
typedef struct {
	int wartosc;
	struct element* nastepny;
}element;
// obiekt stosu ( zawiera wskaznik na 1 element i rozmiar stosu )
typedef struct {
	element *napierwszy;
	int rozmiar;
}stos;
