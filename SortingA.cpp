#include "SortingA.h"

void SortingA::ordenaMerge(vector<Registro>& v)
{
	int n = v.size();

	mergeSort(v, 0, n - 1);
}

void SortingA::mergeSort(vector<Registro>& v, int inicio, int fin)
{
	if (inicio >= fin)
		return;

	int mitad = (inicio + fin) / 2;

	mergeSort(v, inicio, mitad);
	mergeSort(v, mitad + 1, fin);
	merge(v, inicio, mitad, fin);
}

void SortingA::merge(vector<Registro>& v, int inicio, int mitad, int fin)
{
	int n1 = mitad - inicio + 1;
	int n2 = fin - mitad;

	vector<Registro> izq(n1);
	vector<Registro> der(n2);

	for (int i = 0; i < n1; i++)
		izq[i] = v[inicio + i];

	for (int j = 0; j < n2; j++)
		der[j] = v[mitad + 1 + j];

	int i = 0;
	int j = 0;
	int k = inicio;

	while (i < n1 && j < n2)
	{
		if (izq[i].clave() <= der[j].clave())
		{
			v[k] = izq[i];
			i++;
		}
		else
		{
			v[k] = der[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		v[k] = izq[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		v[k] = der[j];
		j++;
		k++;
	}
}
