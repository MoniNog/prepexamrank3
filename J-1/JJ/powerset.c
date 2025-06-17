#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void    print_array(int *a, int len)
{
	int i = 0;
	while (i < len)
	{
		printf("%i ", a[i]);
		i++;
	}
	printf("\n");
}

void powerset(  int *set,
				int *subset,
				int i_set,
				int i_subset,
				int l_set,
				int target,
				int sum
)
{
	if (sum == target)
	{
		print_array(subset, i_subset);
	}

	while (i_set < l_set)
	{
		if (set[i_set] + sum <= target)
		{
			subset[i_subset] = set[i_set];
			powerset(set, subset, i_set + 1, i_subset + 1, l_set, target, sum + set[i_set]);
		}
		i_set++;
	}

}

int main(int ac, char **av)
{
	int target = atoi(av[1]);
	int sum = 0;
	int l_set = ac - 2;

	int *set = calloc(l_set, sizeof(int));
		if (!set)   return 1;
	for (int i = 0; i < l_set; i++)
		set[i] = atoi(av[i + 2]);

	int *subset = calloc(l_set, sizeof(int));
		if (!subset)   return 1;

		

	powerset(
		set,
		subset,
		0,
		0,
		l_set,
		target,
		sum
	);


	free (set);
	free (subset);
}