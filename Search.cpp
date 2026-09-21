#include "Search.h"

int Search::busqBinaria(vector<Registro>& v, int clave)
{
	int inicio = 0;
	int fin = v.size() - 1;
	int pos = v.size();

	while (inicio <= fin)
	{
		int mitad = (inicio + fin) / 2;

		if (v[mitad].clave() >= clave)
		{
			pos = mitad;
			fin = mitad - 1;
		}
		else
			inicio = mitad + 1;
	}

	return pos;
}
