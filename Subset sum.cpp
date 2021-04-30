// Subset Sum problem
#include <iostream>
using namespace std;

int tab[2000][2000];

int isSubsetSum(int set[], int n, int Sum) 
{
	if (Sum==0)
		return 1;
	if (n<=0)
		return 0;
	if (tab[n-1][Sum] != -1)
		return tab[n-1][Sum];
	if (set[n-1]>Sum)
		return tab[n-1][Sum] = isSubsetSum(set, n-1, Sum);
	else {
		return tab[n-1][Sum] = isSubsetSum(set, n-1, Sum) ||
		isSubsetSum(set, n-1, Sum-set[n-1]);
	}
}

int main()
{
	memset(tab, -1, sizeof(tab));
	int set[] = {3, 34, 4, 12, 5, 2};
	int Sum = 9;

	int n = sizeof(set) / sizeof(0);

	if (isSubsetSum(set, n, Sum)) {
		printf("True\n");
	} else {
		printf("False\n");
	}

	return 0;
}