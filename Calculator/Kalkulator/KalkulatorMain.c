#include "Struktura.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "ObslugaStosu.h"

// Said Hannoush Kalkulator RPN 17.01 - 18.01.2022r.


/*
Autor: Said Hannoush
Utwozono: 18.01.2022r.
Wersja: v1.0
Modyfikacje: ¯adne
Program jest kalkulatorem kozystajacym z odwrotnej notacji polskiej.
Wejscie: Program przyjmuje liczby calkowite oraz ponizej opisane litery funkcji i operatory ze domyslnego wejscia.
Wyjscie: Program wypisuje wartosci na wyjsciu domyslnym, domyslnie w terminalu.
Program wpisane liczby wrzuca na stos a wszelkie dzia³ania "+" "-" "*"
Wkonuje na 2 liczbach ze szczytu stosu gdzie odejmuje od 1 liczby na stosie ta druga, usowa te liczby ze stosu i dodaje do niego wynik.
Poza mozliwoscia wprowadzania liczb na stos oraz wykonywania na nich dzialan program po wpisaniu odpowiednich liter wykonuje odpowiednie funkcje:
"p"
	Wyœwitla piersza liczbe ze stosu.
"f"
	Wyswietla wszystkie liczby na stosie od tylu.
"P"
	Usuwa pierwsza liczbe ze stosu
"c"
	Usuwa wszystkie liczby ze stosu.(Czysci stos)
"d"
	Dodaje do stosu kopie pierwszej liczby na stosie.
"r"
	Zamienia miejscami 2 pierwsze liczby na stosie.
"q"
	Konczy dzialanie programu.
*/
int main()
{
	stos liczby;
	element pierwszy;
	inicjacja(&liczby,&pierwszy); // inicjowanie stosu
	int wprogramie = 1;

	while (wprogramie)
	{
		char znak;
		int liczba = INT_MIN; // -2147483648
		int czyliczba;
		char bounty[100];
		scanf("%s", bounty); //wczytywanie
		czyliczba = sscanf(bounty," %d", &liczba);
		if (czyliczba && liczba != INT_MIN) { //sprawdzanie czy wczytana
			dodajelement(&liczby, liczba);
		}
		else
		{
			sscanf(bounty," %c", &znak); // wczytanie operatora lub funkcji
			switch (znak)
			{
				case '+':{  // operator dodawania
					//printf("-- Dodawanie --\n");
					if (liczby.rozmiar < 2) {
						printf("Blad, potrzeba przynajmiej 2 liczb na stosie.\n");
						break;
					}
					int a, b;
					a = usunelement(&liczby);
					b = usunelement(&liczby);
					dodajelement(&liczby, a + b);
					break;
				}
				case '-': { // operator odejmowania
					//printf("-- Odejmowanie --\n");
					if (liczby.rozmiar < 2) {
						printf("Blad, potrzeba przynajmiej 2 liczb na stosie.\n");
						break;
					}
					int a, b;
					a = usunelement(&liczby);
					b = usunelement(&liczby);
					dodajelement(&liczby, a - b);
					break;
				}
				case '*': { // operator mnozenia
					//printf("-- Mnozenie --\n");
					if (liczby.rozmiar < 2) {
						printf("Blad, potrzeba przynajmiej 2 liczb na stosie.\n");
						break;
					}
					int a, b;
					a = usunelement(&liczby);
					b = usunelement(&liczby);
					dodajelement(&liczby, a * b);
					break;
				}
				case 'P': { // opcja zdejmujaca ze stosu
					if (liczby.rozmiar < 1) {
						printf("Blad, brak liczby na stosie.\n");
						break;
					}
					usunelement(&liczby);
					break;
				}
				case 'p': { // opcja wyswietlajaca 1 element stosu
					//printf("-- Print male --\n");
					int a = usunelement(&liczby);
					printf("%d", a);
					dodajelement(&liczby, a);
					break;
				}
				case 'c': { // opcja czyszczaca stos
					//printf("-- Czyszczenie --\n");
					while (liczby.rozmiar > 0) usunelement(&liczby);
					break;
				}
				case 'd': { // opcja duplikujaca 1 element stosu
					//printf("-- Duplikuj --\n");
					int a = usunelement(&liczby);
					dodajelement(&liczby,a);
					dodajelement(&liczby,a);
					break;
				}
				case 'f': { // opcja wyswietlajaca caly stos od tylu
					//printf("-- Printuj elementy --\n");
					int tymroz=0;
					int* wys = malloc(sizeof(int) * liczby.rozmiar);
					for (int i = 0; liczby.rozmiar > 0; i++,tymroz++) {
						wys[i] = usunelement(&liczby);
						printf("%d\n", wys[i]);
					}
					for (; tymroz > 0; tymroz--) dodajelement(&liczby,wys[tymroz - 1]);
					break;
				}
				case 'r': { // opcja zamieniajaca 2 pierwsze elementy stosu
					//printf("-- Odwroc --\n");
					int a, b;
					a = usunelement(&liczby);
					b = usunelement(&liczby);
					dodajelement(&liczby, a);
					dodajelement(&liczby, b);
					break;
				}
				case 'q': { // opcja wyjscia z programu
					printf("Czy na pewno chcesz zamknac program Kalkulator?\n");
					printf("Tak - q     Nie - z\n");
					while(1) {
						char litera;
						scanf("%c", &litera);
						if (litera == 'q' || litera == 'z') {
							if (litera == 'q') wprogramie=0;
							break;
						}
					}
					break;
				}
				default: {
					printf("B³¹d,nie rozpoznano funkcji.\n"); // wrazie wprowadzenia zlego operatora / funcji
					break;
				}
			}
		}
	}
	return 0;
}
/*
* 
******************************Testy**********************************

Test 1:
Czy program poprawnie obsluguje oraz wprowadza liczby na stos i jes wyswietla?
Stdin: 7 8 9 f
Stdout: 9 8 7
Program poprawnie wypisuje liczby.
Program poprawnie wprowadza liczby, obsluguje stos oraz funkcja "f" dziala poprawnie.
Test 2:
Czy dodawanie dziala poprawnie?
Stdin: 7 8 9 + f
Stdout: 17 7
Poprawnie
Program poprawnie dodaje.
Test 3:
Czy odejmowanie dziala poprawnie?
Stdin: 7 8 9 - f
Stdout: 1 7
Poprawnie
Program odejmuje dodaje.
Test 4:
Czy mnozenie dziala poprawnie?
Stdin: 7 8 9 * f
Stdout: 72 7
Poprawnie
Program mnozy poprawnie.
Test 5:
Czy program poprawnie podwaja liczbe?
Stdin: 7 8 9 d f
Stdout: 9 9 8 7
Poprawnie
Program podwaja poprawnie.
Test 6:
Czy program poprawnie zamienia 2 pierwsze liczby?
Stdin: 7 8 9 r f
Stdout: 8 9 7
Poprawnie
Program zamienia poprawnie.
Test 7:
Czy program poprawnie usuwa liczbe?
Stdin: 7 8 9 P f
Stdout: 8 7
Poprawnie
Program usuwa 1 liczbe poprawnie.
Test 8:
Czy program poprawnie czysci stos?
Stdin: 7 8 9 c 5 6 f
Stdout: 6 5
Poprawnie
Program czysci stos poprawnie.
Test 9:
Czy program poprawnie wyswietla 1 liczbe ze stosu?
Stdin: 7 8 9 p
Stdout: 9
Poprawnie
Program wyswietla 1 liczbe poprawnie.
Test 10:
Czy program poprawnie egzekwuje funkcje zamkniecia?
Stdin: q
Stdout: Program pyta czy na pewno chcesz wyjsc?
Stdin: q
Stdout: Program sie zamyka
Poprawnie
Program wykonuje funkcje zamkniecia poprawnie.
***************************************************************************
Wnioski:
Program dziala poprawnie dla przeprowadzanych testow co wskazuje ze podczas dzialania wedlug specyfikacji program powinien dzialac poprawnie.
Program jest slabo uodporniony na bledy oraz probe wpisywania losowych argumentow,
lecz jest to blad nieznaczny poniewaz nic sie nie zdazy w razie wpisania nie istniejacej funkcji.
Program ten niestety posiada limity poniewaz wszyskie liczby sa zapisywane w zmiennej "int",
przez co opsluguje tylko liczby calkowite oraz o pewnym zakresie.
*/