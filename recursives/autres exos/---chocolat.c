// Given three values money, price, and wrap, the task is to find the total number
//  of chocolates you can eat. Here money defines the total amount of money you 
//  have, price is the cost of buying a single chocolate and wrap defines the number
//  of wrappers that can be returned to get one extra chocolate.

// Examples:  

// Input: money = 16, price = 2, wrap = 2
// Output: 15
// Explanation: The price of a chocolate is 2. You can buy 8 chocolates for the amount 16.
// Then return 8 wrappers and get 4 more chocolates. Then you can return 4 wrappers and get 2 more chocolates. 
// Finally, you can return 2 wrappers to get 1 more chocolate. 
// So the total chocolates you eat will be 8 + 4 + 2 + 1 = 15.

// Input: money = 15, price = 1, wrap = 3
// Output: 22
// Explanation: The price of a chocolate is 1. You can buy 15 chocolates for the amount 15. Then return 15 wrappers and get 5 more chocolates. Then you can return 3 wrappers and get 1 more chocolates. Finally, you can return 3 wrappers to get 1 more chocolate. So the total chocolates you eat will be 15 + 5 + 1  + 1 = 22.

// [Naive Approach] Using Recursion : O(logw m/p) Time and O(logw m/p) Space
// The idea is to recursively count the number of chocolates we can eat by returning the wrappers until no more wrappers are left or less than wrap wrappers are left.
#include <stdio.h>

int    f(int choco, int wrap)
{
  int reste;
  if (choco >= wrap)
  {
	  reste = choco % wrap; // 2
	  choco = choco / wrap; // 1 division entière
    return (choco + f(choco + reste, wrap));
  }
  else
    return 0;
}

int first(int price, int money, int wrap)
{
	int choco;
	
	choco = money / price;
	return (choco + f(choco, wrap));
}

int main()
{
	int price = 1;
	int money = 15;
	int wrap = 3;

	printf("nombre de chocolat mange = %i\n", first(price, money, wrap));
}