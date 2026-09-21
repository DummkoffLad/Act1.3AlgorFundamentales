#pragma once
#include <string>
//no queria andar pensando de mas si podia hacerlo asi de a secas asi que decidi hacer una clase porque pos, por eso
using namespace std;

class Registro
{
private:
	int mes;
	int dia;
	int hh;
	int mm;
	int ss;
	string linea;

	int mesANum(string);

public:
	Registro();
	Registro(string);
	Registro(string, int, int, int, int);
	int clave();
	string getLinea();
};
