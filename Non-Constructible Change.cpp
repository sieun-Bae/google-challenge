#include <iostream>
#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins);
void calculate(vector<int> coins, int usedOrNot[], int cnt);
//int minChange();

vector<int> comb;
int numOfCoins;
int Change = 1;

/*
int minChange()
{
	sort(comb.begin(), comb.end());
	int pt = 1;
	int i = 1;
	for (i=1;i<comb[comb.size()-1];i++) { //from 1 to max(comb)
		//if (comb[pt])
	}
	Change = min(Change, i);
}
*/
void calculate(vector<int> coins, int usedOrNot[], int cnt)
{
	if (cnt == numOfCoins) {
		//minChange();
		return;		
	}
	
	for (int i=0;i<cnt;i++) {
		printf("%d ", usedOrNot[i]);
	}
	printf("\n");
	int tmp=0;
	for (int i=0;i<cnt;i++) {
		if (usedOrNot[i])
			tmp+= coins[i];
	}
	comb.push_back(tmp);
	
	//minChange();
	
	usedOrNot[cnt+1] = true;
	calculate(coins, usedOrNot, cnt+1);
	usedOrNot[cnt+1] = false;
	calculate(coins, usedOrNot, cnt+1);

}

int nonConstructibleChange(vector<int> coins) {
	numOfCoins = coins.size();
	bool usedOrNot[numOfCoins];

	usedOrNot[0] = true;
	calculate(coins, usedOrNot, 0);
	
	return Change;
}

int main()
{
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);

	nonConstructibleChange(coins);
	return 0;
}
