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

void	permuter(char *input, int *used, int len_input, int pos, char *output, int i_output)
{
	if (pos == len_input)
	{
		printf("%s\n", output);
		return ;
	}

	while (pos < len_input)
	{
		if (used[pos] == 0)
		{
			output[i_output] = input[pos];
			used[pos] = 1;
			permuter(input, used, len_input, pos + 1, output, i_output + 1);
			used[pos] = 0;
		}
		pos++;
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

		permuter(input, used, len_input, 0, output, 0);
	}
	return 1;
}