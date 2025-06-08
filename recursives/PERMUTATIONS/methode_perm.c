#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

char 	*bubble_sort_str(char *s)
{
    int i, j, len = 0;
    while (s[len])
        len++;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (s[j] > s[j + 1])
                swap(&s[j], &s[j + 1]);
	return s;
}

void	permuter(char *input, int len, char *result, int *used, int pos)
{
	if (pos == len)
	{
		result[pos] = 0;
		printf("%s\n", result);
		return ;
	}

	int j = 0;
	while (j < len)
	{
		if (used[j] == 0)
		{
			if (j > 0 && input[j] == input[j - 1] && used[j - 1] == 0)
			{
				j++;
				continue;
			}
			result[pos] = input[j];
			used[j] = 1;
			permuter(input, len, result, used, pos + 1);
			used[j] = 0;
		}		
		j++;
	}
}


int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *input = strdup(bubble_sort_str(av[1]));
		int 	len = strlen(av[1]);
		char	*result = malloc(sizeof(char) * len + 1);
			if (!result) return 1;
		int 	*used = malloc(sizeof(int) * len + 1);
			if (!used) return 1;
		for (int i = 0; i < len + 1; i++)
		{
			used[i] = 0;
			result[i] = 0;
		}
		permuter(input, len, result, used, 0);
	}
	return 0;
}
