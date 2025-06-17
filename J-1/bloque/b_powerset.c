#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void	powerset(int *set, int i_set, int l_set, int *subset, int i_subset, int sum, int target, int pos)
{
	if (sum == target)
	{
		while (subset[i_subset])
		{
			printf("%i ", subset[i_subset]);
			i_subset++;
		}
		printf("\n");
		return ;
	}

	int i = pos;
	while (i < l_set)
	{
		if (sum + set[pos] <= target)
		{
			subset[i_subset] = set[pos];
			powerset(set, i_set + 1, l_set, subset, i_subset + 1, sum + set[i_set], target, i + 1);
		}
		i++;
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

		powerset(set, 0, l_set, subset, 0, 0, target, 0);	
	}

	return 0;
}