#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


void	filter(char *s, char *x)
{
	int a = 0;
	int i = 0;
	int lens = strlen(s);
	int lenx = strlen(x);
	int start = 0;

	while (s[i])
	{
		a = 0;
		start = i;
		while (s[i] == x[a] && i < lens && a < lenx)
		{
			i++;
			a++;
		}
		if(a == lenx)
		{
			int j = 0;
			while(j < lenx)
			{
				printf("*");
				j++;
			}
			if (i >= lens)
				break;
			continue;
		}
		else
		{	
			i = start;
			printf("%c", s[i]);
		}
		i++;
	}
}

int main()
{
	char *str = "hello worl  d";
	char *o = "lo";

	filter(str, o);
	return 0;
}