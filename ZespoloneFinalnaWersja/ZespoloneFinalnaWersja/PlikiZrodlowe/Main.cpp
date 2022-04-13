#include "Zespolona.h"
#include "Blad.h"
#include "Opcje.h"
#include "Test.h"
#include <fstream>

using namespace std;

int main(int argc, char const **argv) {
	kodbledu blad;
	blad.czyblad = false;
	opcjewywolania opcje;
	opcje.wczytajopcje(blad, argv, argc);
	fstream plik;
	test nowy;
	plik.open(opcje.nazwapliku, ios::in);
	if (nowy.wczytaj(plik)) {
		nowy.wylicz();
		nowy.przeprowadztest();
	}
	else {
		blad.czyblad = true;
		blad.kodbledu = "Nie udalo sie wczytac danych z pliku, plik pusty";
	}
	if (blad.czyblad) blad.wypiszblad();
	return 0;
}