#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_sol(char *clean, int* spaces) {
    int i=0;
	int j=0;
    while (clean[j]) {
        if (spaces[i] == 1)
            printf(" ");
        else 
		{
            printf("%c", clean[j]);
			j++;
		}
        i++;
    }
    printf("\n");
}


/// @brief 
/// @param clean str sans espaces (const)
/// @param len_total len de dirty (const)
/// @param spaces  1 == ' ', 0 == '(' ou ')', tableau int *
/// @param n_spaces nombre d'espaces déjà placés 
/// @param total_spaces nombre total d'espaces (const) clean
/// @param pos index de dirty (sert a initialiser le choix, dépend de l'étape précédente)
void	rip(char *clean, int len_total, int* spaces, int n_spaces, int total_spaces, int pos)
{
    // condition de fin
    if (n_spaces == total_spaces) { // on a placé tous les espaces
        print_sol(clean, spaces);
		return ;
    }

    int i = pos; // initialisation du choix => après le dernier choix fait
    while (i < len_total) {  // exploration des choix
        // validité du choix 
        spaces[i] = 1; // fixe le choix => on place un espace à la pos i 
		rip(clean, len_total, spaces, n_spaces+1, total_spaces, i+1);
        spaces[i] = 0;
        i++;
    }
}

void remove_close(char *s, int score, int i) 
{
	if (i == (int)strlen(s))    //condition de fin
		return;
	
	if (s[i] == ')') {
		if (score <= 0) {    //invalide
			s[i] = ' ';
			remove_close(s, score, i+1);
		} else {            //valide
			remove_close(s, score-1, i+1);
		}
	}
    else if (s[i] == '(') {
        remove_close(s, score+1, i+1);
    }
}

void remove_open(char *s, int score, int i) 
{
	if (i < 0)    //condition de fin
		return;
	
	if (s[i] == '(') {
		if (score >= 0) {    //invalide
			s[i] = ' ';
			remove_open(s, score, i - 1);
		} else {            //valide
			remove_open(s, score + 1, i - 1);
		}
	}
    else if (s[i] == ')') {
        remove_open(s, score - 1, i - 1);
    }
}

int clean_str(char *dirty, char *clean)
{
	int i = 0;
	int j = 0; //nombre de parenthèses
	while(dirty[i])
	{
		if (dirty[i] != ' ') {
			clean[j] = dirty[i];
			j++;
		}
        i++;
	}
    clean[j] = '\0';
	return j;// nombre 
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		char *input = av[1];
		int len = strlen(av[1]);
		char *output = malloc(sizeof(char) * len + 1);
			if (!output)	return 1;
		int len_input = (int)strlen(input);
		puts(input);
		remove_close(input, 0, 0);
		remove_open(input, 0, len_input - 1);
		puts(input);
        char *clean = malloc(sizeof(input));
        int n = clean_str(input, clean);
		puts(clean);
		
		int *spaces = calloc(len, sizeof(int));
		if (!spaces)	return 1;

		rip(clean, len, spaces, 0, len - n, 0);
	}
	return 0;
}