#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void	powerset(int *set, int i_set, int l_set, int *subset, int i_subset, int sum, int target)
{
	if (sum == target)
	{
		int i = 0;
		while (i < i_subset)
		{
			printf("%i ", subset[i]);
			i++;
		}
		printf("\n");
		return ;
	}

	while (i_set < l_set)
	{
		if (sum + set[i_set] <= target)
		{
			subset[i_subset] = set[i_set];
			powerset(set, i_set + 1, l_set, subset, i_subset + 1, sum + set[i_set], target);
		}
		i_set++;
	}
}


int main(int ac, char **av)
{
	if (ac > 2)
	{
		int target = atoi(av[1]);
		int l_set = ac - 2;

		int *set = calloc(l_set, sizeof(int));
			if (!set)	return 1;
		for (int i = 0; i < l_set; i++)
			set[i] = atoi(av[i + 2]);
		
		int *subset = calloc(l_set, sizeof(int));
			if (!subset)	return 1;

		powerset(set, 0, l_set, subset, 0, 0, target);	
	}

	return 0;
}