// Exercice 6 : Trouver le maximum d’un tableau
// Écris une fonction récursive int max_array(int *arr, int size) qui retourne la valeur maximale d’un tableau d’entiers.
#include <stdio.h>

int max_array(int *array, int size)
{
	int i = 0;
	if (!array)
		return -1;
	
	if (array[i] < array[i + 1])
		return (*array + 1, size - 1);
	// else
	// 	array[i]
	// 	return 
}




int main() 
{
	int size = 6;
	int array[6] = {4, 7, 1, 0, 22, 8};

	printf("the max for this array is : %i\n", max_array(array, size));
	return 0;
}
