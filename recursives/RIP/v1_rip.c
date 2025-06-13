#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void	remove_close(char *input, int len, int i, int score)
{
	if (i == len)
	{
		return;
	}
	while (i < len)
	{
		if (input[i] == '(')
			score = score + 1;
		else if (input[i] == ')')
		{
			if (score <= 0)
			{
				input[i] = ' ';
				remove_close(input, len, i + 1, score);
			}	
			else if (score > 0)
			{
				remove_close(input, len, i + 1, score - 1);
			}
		}
		i++;
	}
}

void	remove_open(char *input, int len, int i, int score)
{
	if (i == 0)
	{
		return;
	}
	while (i > 0)
	{
		if (input[i] == ')')
			score = score - 1;
		else if (input[i] == '(')
		{
			if (score >= 0)
			{
				input[i] = ' ';
				remove_open(input, len, i - 1, score);
			}	
			else if (score < 0)
			{
				remove_open(input, len, i - 1, score + 1);
			}
		}
		i--;
	}
}

int	clean_str(char *dirty, char *clean)
{
	int i = 0;
	int j = 0;

	while (dirty[i])
	{
		if (dirty[i] != ' ')
			clean[j++] = dirty[i++];
		else
			i++;
	}
	clean[j] = 0;
	return (j);
}


int main(int ac, char **av)
{
	char *input = av[1];
	int len = (int)strlen(input);
	char *clean = malloc(sizeof(char) * len + 1);
	if (!clean) 	return 0;

	puts(input);
	remove_close(input, len, 0, 0);
	puts(input);
	remove_open(input, len, len - 1, 0);
	puts(input);
	int n_par = clean_str(input, clean);
	puts(clean);
	printf("n_par : %i\n", n_par);
	
	return 0;
}

