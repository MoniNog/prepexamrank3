#include <stdio.h>
#include <string.h>

void	remove_invalid_closing(char *str, int i, int open_count)
{
	if (str[i] == '\0')
		return ;
	if (str[i] == '(')
		remove_invalid_closing(str, i + 1, open_count + 1);
	else if (str[i] == ')')
	{
		if (open_count > 0)
			remove_invalid_closing(str, i + 1, open_count - 1);
		else
		{
			str[i] = ' ';
			remove_invalid_closing(str, i + 1, open_count);
		}
	}
	else
		remove_invalid_closing(str, i + 1, open_count);
}

void	remove_extra_opening(char *str, int i, int *open_count)
{
	if (i < 0 || *open_count == 0)
		return ;
	if (str[i] == '(')
	{
		str[i] = ' ';
		(*open_count)--;
	}
	remove_extra_opening(str, i - 1, open_count);
}

int	main(void)
{
	char	str[] = "(())))(()";
	int		i = 0;
	int		open_count = 0;

	remove_invalid_closing(str, 0, 0);

	// Compter combien de ( restent
	while (str[i])
	{
		if (str[i] == '(')
			open_count++;
		i++;
	}
	remove_extra_opening(str, i - 1, &open_count);

	printf("%s\n", str);
	return (0);
}

