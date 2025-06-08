// Exercice 2 : Somme des entiers
// Écris une fonction récursive int sum(int n) qui calcule la somme des entiers de 1 à n.
#include <stdio.h>
#include <stdlib.h>

int sum(int n)
{
	if (n >= 1)
		return(n + sum(n - 1));
}

int main(int ac, char **av) 
{
	int n = atoi(av[1]);

	printf("the sum of int between %i and 1 is : %i\n", n, sum(n));
	return 0;
}
