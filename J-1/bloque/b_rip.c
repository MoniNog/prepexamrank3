#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void	remove_closed(char *input, int score, int i)
{
	if (input[i] == '(')
		score = score + 1;
	
	else if (input[i] == ')')
	{
		if (score <= 0)
			input[i] = ' ';
		else
			score = score - 1;
		i++;
		remove_closed(input, score, i);
	}
}



int main(int ac, char **av)
{
	char	*input = av[1];
	int 	l_input = (int)strlen(input);
	char	*clean = calloc(l_input, sizeof(char));
				if (!clean)	return 1;
			puts(input);	
	remove_closed(input, 0, 0);
			puts(input);	
	// remove_open(input, l_input, 0);
	// 		puts(input);	
	// clean_str(input, clean);
	// 		puts(clean);	
}