#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

void	swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

char	*sort(char *s, int len)
{
	int i = 0;
	while (i < len - 1)
	{
		int j = 0;
		while (j < len - 1 - i)
		{
			if (s[j] > s[j + 1])
				swap (&s[j], &s[j + 1]);
			j++;
		}
		i++;
	}
}

void	permuter(char *input, char *output, int len, int *used, int pos)
{
	if (pos == len)
	{
		output[pos] = 0;
		puts(output);
		return;
	}
	int i = 0;
	while (i < len)
	{
		if (used[i] == 1)
		{
			i++;
			continue ;
		}
		used[i] = 1;
		output[pos] = input[i];
		permuter(input, output, len, used, pos + 1); 
		used[i] = 0;
		i++;
	}
}



int	main(int ac, char **av)
{
	if (ac > 0)
	{
		int len = ft_strlen(av[1]);
		char *input = av[1];
		char *output = calloc(len + 1, sizeof(char));
		if (!output)	return 1;
		int *used = calloc(len, sizeof(int));
		if (!used)	return 1;
		int pos = 0;

		// puts(input);

		sort(input, len);
		// puts(input);
		permuter(input, output, len, used, 0);
	}
	return 0;
}