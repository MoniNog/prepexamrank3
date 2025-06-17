#include <stdio.h>
#include <stdlib.h>

int	my_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return i;
}

char	swap(char *a, char *b)
{
	char t = *a;
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
				swap(&s[j], &s[j + 1]);
			j++;
		}	
		i++;
	}
}

void	permuter(char *s,
				int len,
				int *used,
				char *out,
				int io,
				int i)
{
	if (i == len)
	{
		out[io] = 0;
		printf("%s", out);
		printf("\n");
		return ;
	}

	while (i < len)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			out[io] = s[i];
			permuter(s, len, used, out, io + 1, i + 1);
			used[i] = 0;			
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*s = av[1];
	int		 len = my_strlen(s);
	int 	*used = calloc(len, sizeof(int));
				if (!used)	return 1;
	char 	*out = calloc(len + 1, sizeof(char));
				if (!out)	return 1;

	bubble_sort(s, len);
	puts(s);
	permuter(s, len, used, out, 0, 0);

	free(used);
	free(out);
}