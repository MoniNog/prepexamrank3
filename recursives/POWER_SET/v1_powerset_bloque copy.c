#include <stdio.h>
#include <stdlib.h>

void	powerset(int target, int sum, int *set, int *subset, int len_set, int len_subset)
{
	if (sum == target)
	{
		for (int i = 0; i < len_subset; i++)
			printf("%i ", subset[i]);
		printf("\n");
		return;
	}
	int i = 0;
	while (i < len_set)
	{
		if (sum <= target)
		{
			subset[len_subset] = set[i];
			sum += subset[len_subset];
			powerset(target, sum, set, subset, len_set + 1, len_subset + 1);
		}
		i++;
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
	powerset(target, sum, set, subset, len_set, len_subset);

}