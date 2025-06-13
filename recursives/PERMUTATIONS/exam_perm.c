#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int ft_strlen(char *s)
{
	int i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void ft_putstr(char *s, int len)
{
	int i = 0;
	while (i < len)
	{
		write(1, &s[i], 1);
		i++;
	}
}

void bubble_sort(char *s, int len)
{
	int i = 0;
	int j = 0;

	while (len > i + 1)
	{
		j = 0;
		while (len > j + 1)
		{
			if (s[j] > s[j + 1])
				swap(&s[j], &s[j + 1]);
			j++;
		}
		i++;
	}
}

void permuter(char *input, int *used, int len, char *output, int io)
{
	if (io == len)
	{
		output[len] = 0;
		ft_putstr(output, len);
		write(1, "\n", 1);
		return;
	}
	int i = 0;
	while (i < len)
	{
		if (used[i] == 1)
		{
			i++;
			continue;
		}
		output[io] = input[i];
		used[i] = 1;
		permuter(input, used, len, output, io + 1);
		used[i] = 0;
		i++;
	}
}

int main(int ac, char **av)
{
	(void)ac;

	if (ac > 1)
	{
		char *input = av[1];
		int len = ft_strlen(input);
		int io = 0;

		int *used = calloc(len, sizeof(int));
			if (!used) return 1;

		char *output = malloc(sizeof(char) * len + 1);
		if (!output) return 1;

		bubble_sort(input, len);
		permuter(input, used, len, output, io);

		free(used);
		free(output);
	}
	return 0;
}
