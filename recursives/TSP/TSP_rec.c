#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 10

int graph[MAX_N][MAX_N];
int min_cost = INT_MAX;

void	tsp(int visited[], int path[], int depth, int current_cost, int N)
{
	if (depth == N)
	{
		int total_cost = current_cost + graph[path[depth - 1]][path[0]];
		if (total_cost < min_cost)
			min_cost = total_cost;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			path[depth] = i;
			tsp(visited, path, depth + 1, current_cost + graph[path[depth - 1]][i], N);
			visited[i] = 0;  // backtrack
		}
	}
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Usage: %s N followed by N*N distances\n", av[0]);
		return (1);
	}
	int N = atoi(av[1]);
	if (ac != 2 + N * N)
	{
		printf("Erreur : il faut %d valeurs pour une matrice %dx%d\n", N * N, N, N);
		return (1);
	}

	// Remplir la matrice
	int idx = 2;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			graph[i][j] = atoi(av[idx++]);

	int visited[MAX_N] = {0};
	int path[MAX_N];

	visited[0] = 1;
	path[0] = 0;

	tsp(visited, path, 1, 0, N);

	printf("Distance minimale : %d\n", min_cost);
	return (0);
}
