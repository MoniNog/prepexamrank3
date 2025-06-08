#include <stdio.h>
#include <stdlib.h>

void find_subsets(int *set, int size, int i, int n, int sum, 
		int *buf_sub, int buf_size)
{
	if (sum == n)
	{
		for (int i = 0; i < buf_size; i++)
			printf("%d ", buf_sub[i]);
		printf("\n");
		return ;
	}
	if (i == size || sum > n)
		return;
	buf_sub[buf_size] = set[i];
	find_subsets(set, size, i + 1, n, sum + set[i], buf_sub, buf_size + 1);
	find_subsets(set, size, i + 1, n, sum, 			buf_sub, buf_size);
}

int main(int ac, char **av)
{
	if (ac < 3) 
		return 1;
	int n = atoi(av[1]);
	int size = ac - 2;
	int set[size], buf_sub[size];
	for (int i = 0; i < size; i++)
		set[i] = atoi(av[i + 2]);
	find_subsets(set, size, 0, n, 0, buf_sub, 0);
	return 0;
}
