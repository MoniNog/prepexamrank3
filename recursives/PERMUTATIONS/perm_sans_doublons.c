#include <stdio.h>
#include <string.h>

// Échange deux caractères
void	swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

// Vérifie si str[i] a déjà été utilisé entre str[start] et str[i - 1]
int	should_skip(char *str, int start, int current)
{
	for (int j = start; j < current; j++)
	{
		if (str[j] == str[current])
			return (1);
	}
	return (0);
}

// Fonction récursive avec détection de doublons
void	permuter_unique(char *str, int start, int end)
{
	if (start == end)
	{
		printf("%s\n", str);
		return ;
	}
	for (int i = start; i <= end; i++)
	{
		if (should_skip(str, start, i)) // déjà utilisé à cette position
			continue;
		swap(&str[start], &str[i]);
		permuter_unique(str, start + 1, end);
		swap(&str[start], &str[i]); // backtrack
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
	permuter_unique(str, 0, len - 1);
	return (0);
}
