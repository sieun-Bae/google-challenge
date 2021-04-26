// Two number Sum
#include <vector>
#include <iostream>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
	vector<int> answer;
 	int len = array.size();
	for (int i=0;i<len;i++) {
		for (int j=0;j<len;j++) {
			if (i==j) continue;
			if (array[i]+array[j] == targetSum) {
				answer.push_back(array[i]);
				answer.push_back(array[j]);
				return answer;
			}
		}
	}
	return answer;
}

int main()
{
	vector<int> array;
	array.push_back(3);
	array.push_back(5);
	array.push_back(-4);
	array.push_back(8);
	array.push_back(11);
	array.push_back(-1);
	array.push_back(1);
	array.push_back(6);

	int targetSum = 10;
	vector<int> answer = twoNumberSum(array, targetSum);
	for (int i=0;i<answer.size();i++) {
		printf("%d ", answer[i]);
	}
	return 0;
}