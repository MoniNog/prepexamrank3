// Exercice 3 : Puissance
// Écris une fonction récursive int power(int base, int exp) qui calcule base élevé à la puissance exp (exp ≥ 0).
#include <stdio.h>
#include <stdlib.h>

int	power(int base, int exp)
{
	if (exp == 0)
		return 1;
	while (exp >= 0)
	{
		return (base * (power(base, exp - 1)));
	}
}

int main(int ac, char **av) 
{
	printf("%i a la puissance %i = %i\n", atoi(av[1]), atoi(av[2]), power(atoi(av[1]), atoi(av[2])));
	return 0;
}
