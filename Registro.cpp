#include "Registro.h"
#include <sstream>

Registro::Registro()
{
	mes = 0;
	dia = 0;
	hh = 0;
	mm = 0;
	ss = 0;
}

Registro::Registro(string txt)
{
	linea = txt;

	string mesTxt, hora;
	istringstream iss(txt);//sacado del gran overflow >> separa apor espacios, creo
	iss >> mesTxt >> dia >> hora;

	mes = mesANum(mesTxt);
	hh = stoi(hora.substr(0, 2));//stoi == string to int
	mm = stoi(hora.substr(3, 2));//lit separando de uqe pso como esta el formato nomas separando pro esos, muy comprehensible mi comentarrio.
	ss = stoi(hora.substr(6, 2));
}

Registro::Registro(string mesTxt, int d, int h, int m, int s)
{
	mes = mesANum(mesTxt);
	dia = d;
	hh = h;
	mm = m;
	ss = s;
}

int Registro::clave()
{
	return mes * 100000000 + dia * 1000000 + hh * 10000 + mm * 100 + ss;
}//para comparar todo con un solo nuemro, me habia salido un tiktok de esto pero no me acordaba muy bien, me lo encontre aqui https://www.geeksforgeeks.org/dsa/sort-an-array-of-string-of-dates-in-ascending-order/

string Registro::getLinea()
{
	return linea;
}

int Registro::mesANum(string txt)
{
	string meses[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
						 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	for (int i = 0; i < 12; i++)
		if (txt == meses[i])
			return i + 1;

	return 0;
}
