#include "Test.h"



bool test::wczytaj(std::fstream& plik) {
	liczbazadan = 0;
	int ilezlych = 0;
	for (int i = 0; !plik.eof();i++)
	{
		plik >> zadania[i];
		if (plik.fail()||zadania[i].czypoprawna==false) {
			i--;
		}
		else liczbazadan++;
		plik.ignore(100,'\n');
	}
	if (liczbazadan < 1) return false;
	return true;
}
bool test::wylicz() {
	for (int i = 0; i < liczbazadan; i++) {
		switch (zadania[i].oper)
		{
		case dodawanie:
			zadania[i].wynik = zadania[i].operand1 + zadania[i].operand2;
			break;
		case odejmowanie:
			zadania[i].wynik = zadania[i].operand1 - zadania[i].operand2;
			break;
		case mnozenie:
			zadania[i].wynik = zadania[i].operand1 * zadania[i].operand2;
			break;
		case dzielenie:
			zadania[i].wynik = zadania[i].operand1 / zadania[i].operand2;
			break;
		default:
			return false;
		}
	}
	return true;
}
bool test::przeprowadztest() {
	using namespace std;
	int wynik = 0;
	cout << "Rozpoczynam Test" << endl;
	cout << "Rozwiaz ponizsze dzialania i wpisz wynik w postaci a+bi" << endl;
	for (int i = 0; i < liczbazadan; i++) {
		liczbazespolona odpowiedz;
		int szansa = 3;
		cout << zadania[i] << endl << endl;
		for (; szansa > 0; szansa--) {
			cin >> odpowiedz;
			cin.ignore(100,'\n');
			cin.clear();
			if (odpowiedz == zadania[i].wynik) {
				wynik++;
				break;
			}
			else if (odpowiedz.czypoprawna) break;
		}

	}
	cout << "Test rozwiazany, oto twoj wynik:" << endl << wynik<< "/" << liczbazadan<< " Prawidlowych odpowiedzi" << endl << 100 * wynik / liczbazadan << "%" << endl;
	return true;
}
std::istream& operator >> (std::istream& strumien, wyrazenie& wyr) {
	wyr.czypoprawna = false;
	char tymOper;
	strumien >> wyr.operand1;
	if (wyr.operand1.czypoprawna == false) return strumien;
	strumien >> tymOper;
	wyr.oper = (operacja)tymOper;
	if (wyr.oper != '+' && wyr.oper != '-' && wyr.oper != '*' && wyr.oper != '/') return strumien;
	if (strumien.get() != ' ') return strumien;
	strumien >> wyr.operand2;
	if (wyr.operand2.czypoprawna == false) return strumien;
	wyr.czypoprawna = true;
	return strumien;
}
std::ostream& operator << (std::ostream& strumien, wyrazenie const& wyr) {
	strumien << "(";
	strumien << wyr.operand1;
	strumien << "i)";
	strumien << (char)wyr.oper;
	strumien << "(";
	strumien << wyr.operand2;
	strumien << "i)";
	return strumien;
}