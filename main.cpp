#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Registro.h"
#include "SortingA.h"
#include "Search.h"

using namespace std;

int main()
{
	ifstream entrada("bitacora.txt");//abre el archivillo

	vector<Registro> datos;
	string linea;

	while (getline(entrada, linea))//getline lee una linea, osea mientras haya lineas hace pusback
		datos.push_back(Registro(linea));

	entrada.close();//cerramos el arvhvivo

	SortingA::ordenaMerge(datos);

	ofstream salida("bitacora_ordenada.txt");

	for (int i = 0; i < datos.size(); i++)
		salida << datos[i].getLinea() << endl;//lit como si fuera el cout solo que lo estamos escribiendo en salida envesde del la cterminal

	salida.close();

	string mesIni, mesFin;
	int diaIni, diaFin;

	cout << "Fecha de inicio" << endl;
	cout << "Mes: ";
	cin >> mesIni;
	cout << "Dia: ";
	cin >> diaIni;

	cout << "Tu ultimo dia" << endl;
	cout << "Mes: ";
	cin >> mesFin;
	cout << "Dia: ";
	cin >> diaFin;

	Registro inicio(mesIni, diaIni, 0, 0, 0);
	Registro fin(mesFin, diaFin, 23, 59, 59);

	int pos = Search::busqBinaria(datos, inicio.clave());

	cout << endl;

	for (int i = pos; i < datos.size() && datos[i].clave() <= fin.clave(); i++)
		cout << datos[i].getLinea() << endl;

	return 0;
}
