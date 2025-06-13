#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	swap(char *a, char *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

char	ft_tolower(char c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return c;
}

void	sort(char *s, int len)
{
	int i = 0;
	int j = 0;

	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (ft_tolower(s[j]) > ft_tolower(s[j + 1]))
				swap(&s[j], &s[j + 1]);
			j++;
		}
		i++;
	}
}

void permuter(char *input, int* used, int len, char *output, int pos)
{
	if (pos == len)
	{
		output[pos] = 0;
		puts(output);
		return ;
	}
	int i = 0;
	while (i < len)
	{
		if (used[i] == 1)
		{
			i++;
			continue ;
		}
		output[pos] = input[i];
		used[i] = 1;
		permuter(input, used, len, output, pos + 1);
		used[i] = 0;
		i++;
	}
}

int main(int ac, char **av)
{
	char *input = av[1];
	int len = strlen(av[1]);
	char *output = malloc(sizeof(char) * len + 1);
		if (!output)		return 1;
	int pos = 0;
	int *used = calloc(len, sizeof(int));
		if (!used)	return 1;

	sort(input, len);
	permuter(input, used, len, output, pos);
	free (output);
	free (used);
}

