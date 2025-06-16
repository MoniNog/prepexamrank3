#include <stdio.h>
#include <stdlib.h>

void	power_set(int target, int set_size, int *set, int index_set, int sum, int *subset_output, int index_output)
{
	if (sum == target)
	{
		for (int i = 0; i < index_output; i++)
			printf("%i ", subset_output[i]);
		printf("\n");
		return ;
	}
	while (index_set < set_size)
	{
		if (sum + set[index_set] <= target)
		{
			subset_output[index_output] = set[index_set];
			power_set(target, set_size, set, index_set + 1, sum + set[index_set], subset_output, index_output + 1);
		}
		index_set++;
	}
}


int main(int ac, char **av)
{
	int target = atoi(av[1]);
	int set_size = ac - 2;
	int *set = malloc (sizeof(int) * set_size);
		if (!set)	return 1;
	for (int i = 0, index_set = 2; i < set_size; i++, index_set++)
		set[i] = atoi(av[index_set]);
	int sum = 0;
	int index_set = 0;

	int *subset_output = malloc (sizeof(int) * set_size);
		if (!subset_output)		return 1;
	int index_output = 0;
	
	power_set(target, set_size, set, index_set, sum, subset_output, index_output);

	free (set);
	free (subset);
}

// int target (av[1])
// int set_size (nombre de nb dans set)
// int *set (rempli avec les arg apres target)