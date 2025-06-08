#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	extract(char *str, char *out, int *space_count)
{
	int	i = 0, j = 0;
	*space_count = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			out[j++] = str[i];
		else
			(*space_count)++;
		i++;
	}
	out[j] = '\0';
}

int	is_already_printed(char *res, char **printed, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(res, printed[i]) == 0)
			return (1);
	}
	return (0);
}

void	place_spaces(char *core, int pos, int len, int *slots, int spaces_left,
				char **printed, int *printed_count)
{
	if (pos == len + 1)
	{
		if (spaces_left == 0)
		{
			char	res[200];
			int		k = 0;

			for (int i = 0; i < len; i++)
			{
				for (int s = 0; s < slots[i]; s++)
					res[k++] = ' ';
				res[k++] = core[i];
			}
			for (int s = 0; s < slots[len]; s++)
				res[k++] = ' ';
			res[k] = '\0';

			if (!is_already_printed(res, printed, *printed_count))
			{
				printf("%s\n", res);
				printed[*printed_count] = strdup(res);
				(*printed_count)++;
			}
		}
		return ;
	}
	for (int s = 0; s <= spaces_left; s++)
	{
		slots[pos] = s;
		place_spaces(core, pos + 1, len, slots, spaces_left - s, printed, printed_count);
	}
}

void	remove_invalid_parentheses(char *str)
{
	int	open = 0, i = 0;

	while (str[i])
	{
		if (str[i] == '(')
			open++;
		else if (str[i] == ')')
		{
			if (open > 0)
				open--;
			else
				str[i] = ' ';
		}
		i++;
	}
	while (--i >= 0)
	{
		if (open > 0 && str[i] == '(')
		{
			str[i] = ' ';
			open--;
		}
	}
}

int	main(int ac, char **av)
{
	char	cleaned[200];
	char	core[200];
	int		spaces, len;
	int		slots[200];
	char	*printed[10000];
	int		printed_count = 0;

	if (ac != 2)
	{
		printf("Usage: %s \"chaine_avec_parentheses\"\n", av[0]);
		return (1);
	}

	strcpy(cleaned, av[1]);
	remove_invalid_parentheses(cleaned);
	extract(cleaned, core, &spaces);
	len = strlen(core);

	printf("Chaîne nettoyée : \"%s\"\n", cleaned);
	printf("\nCombinaisons valides différentes :\n");
	place_spaces(core, 0, len, slots, spaces, printed, &printed_count);

	for (int i = 0; i < printed_count; i++)
		free(printed[i]);
	return (0);
}
