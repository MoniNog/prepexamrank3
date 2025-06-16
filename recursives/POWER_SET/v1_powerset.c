#include <stdio.h>
#include <stdlib.h>

void	powerset(int target, int sum, int *set, int *subset, int len_set, int i_sub, int i_set)
{
	if (sum == target)
	{
		for (int i = 0; i < i_sub; i++)
			printf("%i ", subset[i]);
		printf("\n");
		return;
	}
	while(i_set < len_set)
	{
		if (sum + set[i_set] <= target)
		{
			subset[i_sub] = set[i_set];
			powerset(target, sum + set[i_set], set, subset, len_set, i_sub + 1, i_set + 1);
		}
		i_set++;
	}
}


int main (int ac, char **av)
{
	int target = atoi(av[1]);

	int len_set = ac - 2;

	int *set = calloc(len_set, sizeof(int));
		if (!set)	return 1;
	for (int i = 0; i < len_set; i++)
		set[i] = atoi(av[i + 2]);

	int *subset = calloc(len_set, sizeof(int));
		if (!subset)	return 1;

	int i_set = 0;
	int i_sub = 0;
	int sum = 0;

	powerset(target, sum, set, subset, len_set, i_sub, 0);

	free (set);
	free (subset);
}