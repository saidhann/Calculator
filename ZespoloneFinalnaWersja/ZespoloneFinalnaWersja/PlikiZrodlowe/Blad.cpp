#include "Blad.h"
void kodbledu::wypiszblad() {
	if (czyblad) {
		std::cout << "Wystapil blad" << std::endl;
		std::cout << kodbledu << std::endl;
	}
}
