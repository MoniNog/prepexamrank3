#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define YES 1
#define NO 0

void	swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

char	*bubble_sort_s(char *s)
{
	int i;
	while (s[i + 1])
	{
		i = 0;
		while (s[i + 1] && s[i] > s[i + 1])
			swap(&s[i], &s[i + 1]);
	}
	i++;
}
int	should_skip(char *s, int i)
{
	if (s[i] && s[i + 1] && s[i] == s[i + 1])
		return YES;
}

/// @brief fonction permettant de swaper les lettres autant de fois que cest possible puis de passer a la suivante. 
/// @param s input a traiter
/// @param start index indiquant la case de la permutation actuelle
/// @param end fin de la string, strlen(s)
void	permuter(char *s, int start, int end)
{
	if (start == end)
	{
		printf("%s\n", s);
		return;
	}
	int i = start;
	while (i < end)
	{
		if (start != 0)
			swap(&s[start], &s[i]);
		permuter(s, start + 1, end);
			// swap(&s[start], &s[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2 && av[1] != 0)
	{
		bubble_sort_s(av[1]);
		permuter(av[1], 0, strlen(av[1]));
	}
	printf("\n");
	return 0;
}


