#include <stdlib.h>	
#include <stdio.h>
	
void	find_subset(int target, int *set, int len_set, int sum, int *subset, int num_in_subset, int current)
{
	if (sum == target) // condition de fin
	{
	for (int j = 0; j < num_in_subset; j++)
			printf("%i ", subset[j]);
		printf("\n");
		return;
	}
	// if current == len_set => return redondant avec la boucle while...
	int i = current;					// debut de letape
	while (i < len_set)				// exploration de tous les choix pour cette étape
	{
		if (sum + set[i] <= target) 	//choix valide ? pouquoi <= et pas < ? question a repondre par moni
			{
				subset[num_in_subset] = set[i];															// on fixe le choix (dans la solution)
				find_subset(target, set, len_set, sum + set[i], subset, num_in_subset + 1, i + 1);			// on continue à construire la solution => étape suivante
			}													
		i++;
	}
}// return; sous entendu

int main(int ac, char **av)
{
	int target = atoi(av[1]);
	int len_set = ac - 2;
	int *set = malloc(sizeof(int) * len_set);
		if (!set)	return 1;
	for (int i = 0; i < len_set; i++)
		set[i] = atoi(av[i + 2]);

	int *subset = malloc(sizeof(int) * len_set);
		if (!subset)	return 1;

	find_subset(target, set, len_set, 0, subset, 0, 0);
	free(set);
	free(subset);
}