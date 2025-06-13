#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define N_SIZE 4

int	check_sum(int **matrix, int size, int *current_loop)
{
	int sum = 0;
	int i = 0;
	for(int j = 0; j < size; j++)
		printf("%i ", current_loop[j]);
	while (i + 1 < size)
	{
		sum += matrix[current_loop[i]][current_loop[i + 1]];
		i++;
	}
	sum += matrix[current_loop[i]][current_loop[0]]; // retour a la premiere ville
	return (sum);
}

void stock_path(int* shortest_loop, int* current_loop, int size) {
	int i = 0;
	
	while (i < size){
		shortest_loop[i] = current_loop[i];
		i++;		
	}
}

void tsp(int **matrix, int size, int shortest_sum, int *shortest_loop, int n_cities, int *current_loop, int* visited_cities)
{
	if (n_cities == size)
	{
		if (check_sum(matrix, size, current_loop) < shortest_sum)
			stock_path(shortest_loop, current_loop, size);
		return;	
	}

	int i = 0;
	while (i < size) 
	{										// explorer les choix à cette étape
		if (visited_cities[i] == 0) 			// check if choice is valid  
		{			
			current_loop[n_cities] = i;		//j'ajoute la ville à mon loop
			visited_cities[i] = 1;			//j'indique que elle est visitée
			tsp(matrix, size, shortest_sum, shortest_loop, n_cities+1, current_loop, visited_cities);	// explore from choice
			visited_cities[i] = 0;			//avant de passer au choix suivant, j'enlève 
		}
		i++;
	}

}

int main (int ac, char **av)
{
	int matrix[4][4] = {
	{0, 2, 9, 10},
	{1, 0, 6, 4},
	{15, 7, 0, 8},
	{6, 3, 12, 0}
	};
	
	int size = N_SIZE;

	int shortest_sum = INT_MAX;
	int *shortest_loop = malloc(sizeof(int) * N_SIZE);
		if (!shortest_loop)	return 1;
	int n_cities = 0;
	int *current_loop = malloc(sizeof(int) * N_SIZE);
		if (!current_loop)	return 1;
	int *visited_cities = malloc(sizeof(int) * N_SIZE);
		if (!visited_cities)	return 1;
	for(int i = 0; i < size; i++)
		visited_cities[i] = 0;

	tsp((int **)matrix, size, shortest_sum, shortest_loop, n_cities, current_loop, visited_cities);
	for(int i = 0; i < size; i++)
		printf("%i ", shortest_loop[i]);
	printf("\n");

}


// "À cette étape, quelle(s) variable(s) me disent “où j’en suis” ?"
// le nombre de voyage entre deux destinations,
// le nombre destinations parcouru

// "Quelles sont les valeurs possibles à tester ?"

// "Si j’en essaye une, comment je l’enregistre/je marque ?"

// "Comment je reviens en arrière après avoir exploré cette branche ?"


// calculer les differents chemins, 
// puisque pas pareil dans les deux sens, 
// pas possible de /2

// ABCD, toutes les combinaisons possibles 
// ab = 1
// bc = 7
// cd = 12
// da = 10

// somme 1, 7, 12, 10 = 30

// je teste, je garde le meilleur chemin (le plus court)
// comment stocker les resultats ? 
// est ce que je trie au fur et a mesure ? 
// 	(je garde toujours le meilleur)