#pragma once
#include <string>
#include "blad.h"

class opcjewywolania {
public:
	std::string nazwapliku;
	void wczytajopcje(kodbledu& blad, char const** argv, int const& argc);
};