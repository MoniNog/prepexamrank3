#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void	remove_closed(char *s, int score, int i, int l_input)
{
	if (i == l_input)
		return;

	if (s[i] == '(')
		score = score + 1;
	
	else if (s[i] == ')')
	{
		if (score <= 0)
			s[i] = ' ';
		else
			score = score - 1;
	}
	i++;
	remove_closed(s, score, i, l_input);
}


void	remove_open(char *s, int score, int i, int l_input)
{
	if (i == 0)
		return;

	if (s[i] == ')')
		score = score - 1;
	
	else if (s[i] == '(')
	{
		if (score >= 0)
			s[i] = ' ';
		else
			score = score + 1;
	}
	i--;
	remove_open(s, score, i, l_input);
}

int clean_str(char *clean, char *dirty)
{
	int i = 0;
	int j = 0;
	while (dirty[i])
	{
		if (dirty[i] == ' ')
			i++;
		else
		{
			clean[j] = dirty[i];
			i++;
			j++;
		}
	}
	return j;
}

void	print_par(char *s, int *used, int len)
{
	int i = 0;
	int j = 0;
	while (i < len)
	{
		if (used[i] == 1)
			printf(" ");
		else
		{
			printf("%c", s[j]);
			j++;
		}
		i++;
	}
	// s[i] = 0;
}

void	rip(int l_in, int l_out, int pos, int *used, int tot_space, int n_spaces, char *s)
{
	if (tot_space == n_spaces)
	{
		print_par(s, used, l_in);
		printf("\n");
		return;
	}

	while (pos < l_in)
	{
			used[pos] = 1;
			rip(l_in, l_out, pos + 1, used, tot_space, n_spaces + 1, s);
			used[pos] = 0;
	
			pos++;
	}
}

int main(int ac, char **av)
{
	char	*s = av[1];
	int 	l_input = (int)strlen(s);
	char	*clean = calloc(l_input, sizeof(char));
				if (!clean)	return 1;
			puts(s);	
	remove_closed(s, 0, 0, l_input);
			puts(s);	
	remove_open(s, 0, l_input, l_input);
			puts(s);	
	int l_out = clean_str(clean, s);
			puts(clean);	

	int *used = calloc(l_input, sizeof(int));
		if (!used)	return 1;

	rip(l_input, l_out, 0, used, l_input - l_out, 0, clean);
	
}