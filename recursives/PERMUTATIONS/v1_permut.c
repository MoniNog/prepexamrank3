#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

char swap(char *a, char *b)
{
	char t = *a;
	*a = *b;
	*b = t;
}

void bubble_sort(char *s, int len)
{
	int i = 0;
	int j = 0;
	while (len > i + 1)
	{
		j = 0;
		while (len > j + 1 + i)
		{
			if (s[j] > s[j + 1])
				swap (&s[j], &s[j + 1]);
			j++;
		}
		i++;
	}
}

void	permut(char *input, int len, int *used, int pos, char *output)
{
	if (pos == len)
	{
		output[pos] = 0;
		printf("%s\n", output);
		return ;
	}
	int i = 0;
	while (i < len)
	{
		if (used[i] == 0)
		{
			output[pos] = input[i];
			used[i] = 1;
			permut(input, len, used, pos + 1, output);
			used[i] = 0;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *input = av[1];
		int len = my_strlen(input);
		int *used = calloc(len, sizeof(int));
			if (!used)	return 1;
		char *output = calloc(len, sizeof(char) + 1);
			if (!output)	return 1;
		
			puts(input);
		bubble_sort(input, len);
			puts(input);
		permut(input, len, used, 0, output);
	}
	return 0;
}