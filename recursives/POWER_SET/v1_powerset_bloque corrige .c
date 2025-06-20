#include <stdio.h>
#include <stdlib.h>

void	powerset(int target, int sum, int *set, int *subset, int len_set, int len_subset, int i_set, int i_sub)
{
	if (sum == target)
	{
		for (int i = 0; i < len_subset; i++)
			printf("%i ", subset[i]);
		printf("\n");
		return;
	}
	while (i_set < len_set)
	{
		if (sum + set[i_set] <= target)
		{
			subset[i_sub] = set[i_set];
			powerset(target, sum + set[i_set], set, subset, len_set, len_subset + 1, i_set + 1, i_sub + 1);
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
	int len_subset = 0;
	int sum = 0;
	powerset(target, sum, set, subset, len_set, len_subset, 0, 0);

}