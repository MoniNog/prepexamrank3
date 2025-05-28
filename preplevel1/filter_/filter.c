#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t ft_strlen(const char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}
char *ft_strdup(const char *s)
{
	int i = 0;
	
	if (!s)
	return (NULL);
	
	char *str;
	str = malloc(sizeof(char) * (int)ft_strlen(s));
	if (!str)
		return (NULL);
	
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*filter(char *s, char *x)
{
	int lens = ft_strlen(s);
	int lenx = ft_strlen(x);
	int i = 0;
	int a = 0;
	int start = 0;

	char *str = ft_strdup(s);
	if (!str)
		return NULL;

	while (s[i])
	{
		start = i;
		a = 0;
		if (s[i] && x[a] && s[i] == x[a])
		{
			i++;
			a++;
		}
		if (!x[a])
		{
			int j = 0;
			while (j < lenx)
			{
				str[j + start] = '*';
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
	return (str);
}

int main(int ac, char ** av)
{
	char *s = "Hello world";
	char *x = "o";
	printf("%s\n", filter(s, x));
}