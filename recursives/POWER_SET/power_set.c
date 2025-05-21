#include <stdio.h>
#include <stdlib.h>

// Compare pour qsort
int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

// Backtracking pour trouver les combinaisons qui font "target"
void	find_combinations(int nums[], int size, int target, int sum, int index,
						int path[], int path_size)
{
	if (sum == target)
	{
		printf("{ ");
		for (int i = 0; i < path_size; i++)
			printf("%d ", path[i]);
		printf("}\n");
		return;
	}
	if (sum > target)
		return;
	for (int i = index; i < size; i++)
	{
		if (i > index && nums[i] == nums[i - 1])
			continue;
		path[path_size] = nums[i];
		find_combinations(nums, size, target, sum + nums[i], i + 1, path, path_size + 1);
	}
}

int	main(int ac, char **av)
{
	if (ac < 3)
	{
		printf("Usage: %s target num1 num2 ...\n", av[0]);
		return (1);
	}

	int	target = atoi(av[1]);
	int	nums[ac - 2];
	int	path[ac - 2];

	// Convertir les arguments en int
	for (int i = 2; i < ac; i++)
		nums[i - 2] = atoi(av[i]);

	int size = ac - 2;

	// Trier pour faciliter la gestion des doublons
	qsort(nums, size, sizeof(int), compare);

	// Appel principal
	find_combinations(nums, size, target, 0, 0, path, 0);

	return (0);
}
