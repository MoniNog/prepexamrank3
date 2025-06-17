#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void remove_close(char* s, int score, int i)
{
	if (i == (int)strlen(s))    //condition de fin
		return;

	if (s[i] == ')') {
		if (score <= 0) {    //invalide
			s[i] = ' ';
			remove_close(s, score, i + 1);
		}
		else {            //valide
			remove_close(s, score - 1, i + 1);
		}
	}
	else if (s[i] == '(') {
		remove_close(s, score + 1, i + 1);
	}
}


void remove_open(char* s, int score, int i)
{
	if (i < 0)    //condition de fin
		return;

	if (s[i] == '(') {
		if (score >= 0) {    //invalide
			s[i] = ' ';
			remove_open(s, score, i - 1);
		}
		else {            //valide
			remove_open(s, score + 1, i - 1);
		}
	}
	else if (s[i] == ')') {
		remove_open(s, score - 1, i - 1);
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

void print_par(char *s, int len, int *spc_placed)
{
	int i = 0;
	int j = 0;
	while (s[i])
	{
		if (spc_placed[i] == 1)
			printf(" ");
		else
			printf("%c", s[j++]);
		i++;
	}
	printf("\n");
}

void	rip(
			int *spc_placed,
			int tot_spc,
			int n_spc_placed,
			char *clean,
			int l_dirty,
			int pos
)
{
	if (tot_spc == n_spc_placed)
	{
		print_par(clean, l_dirty, spc_placed);
		return;
	}

	int i = pos;
	while (i < l_dirty)
	{
		spc_placed[i] = 1;
		rip(spc_placed, tot_spc, n_spc_placed + 1, clean, l_dirty, i + 1);
		spc_placed[i] = 0;
		i++;
	}
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
	remove_close(input, 0, 0);
		puts(input);
	remove_open(input, 0, len - 1);
		puts(input);
	int n_par = clean_str(input, clean);
		// puts(clean);
		// printf("n_par : %i\n", n_par);
	int total_spaces = len - n_par;

	rip(spaces_placed, total_spaces, 0, clean, len, 0);


	return 0;
}

