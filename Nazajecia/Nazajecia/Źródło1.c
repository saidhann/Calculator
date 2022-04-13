#include <stdio.h>
#include <stdlib.h>

typedef struct obiekt {

	int obiekt;
	struct obiekt* nast;

} strk;
void init(strk* nazwa)
{
	nazwa->nast = NULL;
}
void push(strk* nazwa, int element)
{
	strk* wsk = malloc(sizeof(strk));
	wsk->nast = nazwa->nast;
	wsk->obiekt = element;
	nazwa->nast = wsk;
}
int pop(strk* nazwa)
{
	if (nazwa->nast == NULL) return 0;
	int wartosc = nazwa->nast->obiekt;
	strk* t = nazwa->nast;
	nazwa->nast = nazwa->nast->nast;
	free(t);
	return wartosc;
}
int empty(strk* nazwa)
{
	return nazwa->nast != NULL;
}
int print(strk* nazwa)
{
	while (nazwa->nast)
	{
		printf("%d\n", nazwa->nast->obiekt);
		nazwa = nazwa->nast;
	}
}

int main()
{
	strk stos;
	int arg;
	init(&stos);
	arg = 7;
	push(&stos, arg);
	arg = 14;
	push(&stos, arg);
	print(&stos);
	arg = pop(&stos);
	print(&stos);
	printf("Zdjeta wartosc:%d\n", arg);
	return 0;
}