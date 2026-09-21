#pragma once
#include <vector>
#include "Registro.h"

using namespace std;

class SortingA
{
private:
	static void mergeSort(vector<Registro>&, int, int);
	static void merge(vector<Registro>&, int, int, int);

public:
	static void ordenaMerge(vector<Registro>&);
};
