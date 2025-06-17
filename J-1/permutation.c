#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	my_swap(char *a, char *b)
{
	char t= *a;
	*a = *b;
	*b = t;
}

void	bubble_sort(char *s, int len)
{
	int i = 0;
	int j = 0;
	while (len > i + 1)
	{
		j = 0;
		while (len > j + 1 + i)
		{
			if (s[j] > s[j + 1])
				my_swap (&s[j], &s[j + 1]);
			j++;
		}
		i++;
	}
}

void	permuter(char *input, int *used, int len_input, char *output, int pos)
{
	if (pos == len_input)
	{
		output[pos] = 0;
		printf("%s\n", output);
		return ;
	}

	int i = 0;
	while (i < len_input)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			output[pos] = input[i];
			permuter(input, used, len_input, output, pos + 1);
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
		int len_input = my_strlen(input);
			puts(input);
		bubble_sort(input, len_input);
			puts(input);
		int *used = calloc(len_input, sizeof(int));
			if (!used)	return 1;
		char *output = calloc(len_input, sizeof(char));
			if (!output)	return 1;

		permuter(input, used, len_input, output, 0);
	}
	return 1;
}