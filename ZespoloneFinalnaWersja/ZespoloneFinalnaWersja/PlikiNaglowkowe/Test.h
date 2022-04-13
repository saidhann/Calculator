#pragma once
#include <fstream>
#include <iostream>
#include "Zespolona.h"
#include <string>

enum operacja {
	dodawanie = '+',
	odejmowanie = '-',
	mnozenie = '*',
	dzielenie = '/'
};
class wyrazenie {
public:
	liczbazespolona operand1;
	liczbazespolona operand2;
	liczbazespolona wynik;
	operacja oper;
	bool czypoprawna;
};
class test {
public:
	int liczbazadan;
	double wynik;
	wyrazenie zadania[100];
	bool wczytaj(std::fstream& plik);
	bool wylicz();
	bool przeprowadztest();
};

std::istream& operator >> (std::istream& strumien, wyrazenie& wyr);
std::ostream& operator << (std::ostream& strumien, wyrazenie const& wyr);