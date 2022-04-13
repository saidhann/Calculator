#pragma once
#include <istream>
#include <ostream>
#include <string>
#include <sstream>
class liczbazespolona {
public:
	double rzeczywista;
	double urojona;
	bool czypoprawna;
	liczbazespolona operator + ( liczbazespolona const& druga) const;
	liczbazespolona operator - ( liczbazespolona const& druga) const;
	liczbazespolona operator * ( liczbazespolona const& druga) const;
	liczbazespolona operator / ( liczbazespolona const& druga) const;
	liczbazespolona operator = ( liczbazespolona const& druga);
	bool operator == (liczbazespolona const& druga) const;
};
std::istream& operator >> (std::istream& strumien, liczbazespolona& zespolona);
std::ostream& operator << (std::ostream& strumien, liczbazespolona const& zespolona);