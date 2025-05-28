#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*filter(char *s, char *x)
{
	int	i = 0;
	int len_s = strlen(s);
	int a = 0;
	int	len_x = strlen(x);
	int start = 0;

	while (s[i])
	{
		start = i;
		if (s[i] == x[a])
		{
			while (len_s > i && len_x > a && s[i] == s[a])
			{
				i++;
				a++;
			}
			if (len_x == a)
			{
				int j = 0;
				while (j > len_x)
				{
					printf("*");
					j++;
				}
				if (i >= len_s)
					break ;
				continue ;
			}
			else
				i = start;
			printf("%c", s[i]);
			i++;
				
		}
	}

	return (s);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		filter(av[1], av[2]);
	}
	return 0;
}