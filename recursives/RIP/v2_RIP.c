#include <stdio.h>
#include <stdlib.h>

int	my_strlen(char *s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void remove_close(char *s, int i, int score, int len)
{
	if (len == i)
		return;

	if (s[i] == '(')
			score++;
			
	else if (s[i] == ')')
	{
		if (score <= 0)
			s[i] = ' ';
		else 
			score--;
	}
	i++;
	remove_close(s, i, score, len);
}

void remove_open(char *s, int i, int score, int len)
{
	if (0 == i)
		return;

	while (0 < i)
	{
		if (s[i] == ')')
			score = score - 1;

		else if (s[i] == '(')
		{
			if (score >= 0)
			{
				s[i] = ' ';
				remove_open(s, i - 1, score, len);
			}
			else 
				remove_open(s, i - 1, score + 1 , len);
		}
		i--;
	}
}

int		clean_str(char *clean, char *dirty)
{
	int i_dirty = 0;
	int i_clean = 0;
	while (dirty[i_dirty])
	{
		if (dirty[i_dirty] != ' ')
		{
			clean[i_clean] = dirty[i_dirty];
			i_clean++;
		}
		i_dirty++;
	}
	clean[i_clean] = 0;
	return (i_clean);
}

void	print_sol(char *clean, int *pos_spaces, int len_input)
{
	int i = 0;
	int j = 0;
	while (i < len_input)
	{
		if (pos_spaces[i] == 0)
		{
			printf("%c", clean[j]);
			j++;
		}
		else
			printf(" ");
		i++;
	}
}

void	rip(char *clean, 
			int len_input, 
			int tot_spaces, 
			int n_space_placed, 
			int *pos_spaces,
			int pos)
{
	if (tot_spaces == n_space_placed)
	{
		print_sol(clean, pos_spaces, len_input);
		printf("\n");
		return;
	}
	int i = pos; // d'utiliser une variable differente (i pour incrementer et parametrer la boucle while, bonne pratique)		
	while (i < len_input)
	{
		pos_spaces[i] = 1;
		rip(clean, len_input, tot_spaces, n_space_placed + 1, pos_spaces, i + 1);
		pos_spaces[i] = 0;

		i++;
	}
}



int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *input = av[1];
		int len_input = my_strlen(input);
		char *clean = calloc(len_input, sizeof(char));
			if(!clean)	return 1;
		int len_clean;
		
			puts(input);
		remove_close(input, 0, 0, len_input);
			puts(input);
		remove_open(input, len_input, 0, len_input - 1);
			 puts(input);
		len_clean = clean_str(clean, input);
			puts(clean);
		int tot_space = len_input - len_clean;
		int n_space_placed = 0;
		int *pos_spaces = calloc(len_input, sizeof(int));

		rip(clean, len_input, tot_space, n_space_placed, pos_spaces, 0);

		free (clean);
	}
}