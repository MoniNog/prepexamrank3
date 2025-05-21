#include <stdio.h>
#include <string.h>

// Échange deux caractères
void	swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

// Fonction récursive pour générer les permutations
void	permuter(char *str, int start, int end)
{
	if (start == end)
	{
		printf("%s\n", str);
		return ;
	}
	for (int i = start; i <= end; i++)
	{
		swap(&str[start], &str[i]);              // on place str[i] au début
		permuter(str, start + 1, end);           // on permute le reste
		swap(&str[start], &str[i]);              // backtrack (on remet comme avant)
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: %s \"chaine\"\n", av[0]);
		return (1);
	}
	char str[100];
	strncpy(str, av[1], 99);
	str[99] = '\0';

	int len = strlen(str);
	permuter(str, 0, len - 1);
	return (0);
}
