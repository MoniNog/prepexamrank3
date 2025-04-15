#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

// filter corrige avec Elise
char *filter(char *s, char *x)
{
	int i = 0;
	int a = 0;
	int lenx = strlen(x);
	int lens = strlen(s);
	int start = 0;
	char *str;

	str = malloc(sizeof(char) * lens);

	while (i < lens)
	{
		start = i;
		a = 0;
		while (s[i] && x[a] && s[i] == x[a])
		{
			i++;
			a++;
		}
		if (a == lenx)
		{
			int j = 0;
			while (j < lenx)
			{
				str[start+j] = '*';
				j++;
			}
			if (!s[i])
				break ;
			continue ;
		}
		i = start;
		str[i] = s[i];
		i++;
	}
	str[lens] = '\0';
	return str;
}

int main(int ac, char **av)
{
	
	// printf("%s\n", filter("bonjoour oole monde", "oo"));
	return 0;
}