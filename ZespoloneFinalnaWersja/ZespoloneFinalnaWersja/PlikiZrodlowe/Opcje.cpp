#include <string>
#include "Opcje.h"
#include "Blad.h"

void opcjewywolania::wczytajopcje(kodbledu& blad, char const** argv, int const& argc) {
	if (argc == 2) {
		nazwapliku = argv[1];
	}
	else {
		if (argc == 1) {
			blad.czyblad = 1;
			blad.kodbledu = "Nie podano pliku docelowego z egzaminem";
		}
		else {
			blad.czyblad = 1;
			blad.kodbledu = "Podano za duzo argumentow wywolania";
		}
	}
}