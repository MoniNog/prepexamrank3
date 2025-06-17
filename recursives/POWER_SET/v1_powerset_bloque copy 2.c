#include <stdio.h>
#include <stdlib.h>

void	powerset(int target, int sum, int *set, int *subset, int len_set, int i_subset, int pos_set)
{
	if (sum == target)
	{
		for (int i = 0; i < i_subset; i++)
			printf("%i ", subset[i]);
		printf("\n");
		return;
	}
	int i = pos_set;// besoin dun index exterieur pour ne pas repetition. initialisation du choix depend du choix que jai fiat a letape precedente
	while (i < len_set)
	{
		if (sum + set[i] <= target)
		{
			subset[i_subset] = set[i];
			powerset(target, sum + set[i], set, subset, len_set, i_subset + 1, i + 1);
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
	int sum = 0;
	powerset(target, sum, set, subset, len_set, 0, 0);

}