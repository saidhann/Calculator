#include "Zespolona.h"

using namespace std;

liczbazespolona liczbazespolona::operator + (liczbazespolona const& druga) const {
	return { rzeczywista + druga.rzeczywista ,urojona + druga.urojona };
}
liczbazespolona liczbazespolona::operator - (liczbazespolona const& druga) const {
	return { rzeczywista - druga.rzeczywista , urojona - druga.urojona };
}
liczbazespolona liczbazespolona::operator * ( liczbazespolona const& druga) const {
	return { rzeczywista * druga.rzeczywista - urojona * druga.urojona , urojona * druga.rzeczywista + druga.urojona * rzeczywista };
}
liczbazespolona liczbazespolona::operator = (liczbazespolona const& druga) {
	rzeczywista = druga.rzeczywista;
	urojona = druga.urojona;
	return { druga.rzeczywista,druga.urojona };
}
liczbazespolona liczbazespolona::operator / ( liczbazespolona const& druga) const {
	return { (rzeczywista*druga.rzeczywista + urojona*druga.urojona)/(druga.urojona*druga.urojona+druga.rzeczywista*druga.rzeczywista),(urojona*druga.rzeczywista-rzeczywista*druga.urojona)/ (druga.urojona * druga.urojona + druga.rzeczywista * druga.rzeczywista) };
}
bool liczbazespolona::operator == (liczbazespolona const& druga) const {
	return { rzeczywista == druga.rzeczywista && urojona == druga.urojona };
}
std::istream& operator >> (std::istream& strumien , liczbazespolona& zespolona) {
	zespolona.czypoprawna = false;



	if (strumien.get() != '(') return strumien;
	strumien >> zespolona.rzeczywista;
	if (strumien.fail()) return strumien;
	strumien >> zespolona.urojona;
	if (strumien.fail()) return strumien;
	if (strumien.get() != 'i') return strumien;
	if (strumien.get() != ')') return strumien;
	zespolona.czypoprawna = true;
	return strumien;
}
std::ostream& operator << (std::ostream& strumien, liczbazespolona const& zespolona) {
	
	strumien << zespolona.rzeczywista;
	if (zespolona.urojona >= 0) strumien << "+";
	strumien << zespolona.urojona;
	return strumien;
}