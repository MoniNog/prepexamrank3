#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_rip(int *spaces_placed, char *clean, int len)
{
	int i = 0;
	int j = 0;
	while (i < len)
	{
		if (spaces_placed[i] == 1)
			printf(" ");
		else
			printf("%c", clean[j++]);
		i++;
	}
	printf("\n");
}

void	rip(int n_spaces, 
			int len_total, 
			int *spaces_placed, 
			char *clean, 
			const int total_spaces, 
			int pos)
{
	if (n_space
	int i = 0;
	while (i < )
	{

		i++;
	}
}

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
		if (!clean)			return 1;
	int *spaces_placed = calloc(len, sizeof(int));
		if (!spaces_placed)	return 1;

		puts(input);
	remove_close(input, len, 0, 0);
		puts(input);
	remove_open(input, len, len - 1, 0);
		puts(input);
	int n_par = clean_str(input, clean);
		puts(clean);
		printf("n_par : %i\n", n_par);
	int n_spaces = len - n_par;

	rip(0, len, spaces_placed, clean, n_spaces, 0);

	return 0;
}

