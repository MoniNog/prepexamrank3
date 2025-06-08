// Exercice 1 : Factorielle
// Écris une fonction récursive int factorial(int n) qui calcule la factorielle de n (avec factorial(0) = 1).
#include <stdio.h>

int factorial(int n)
{
	if (n == 0)
		return 1;
	while (n > 0)
		return(n * factorial(n - 1));
		//	   5 * (5 - 1)!
		//	   n *	  4! -> facotrial(n - 1)
}

int main() 
{
	int n = 6;
	printf("factorial de %i! = %i\n", n, factorial(n));
	return 0;
}
