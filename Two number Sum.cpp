// Two number Sum
#include <vector>
#include <unordered_set>
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
// 2. Using unordered set
// O(N) time | O(N) space
vector<int> twoNumberSum2(vector<int> array, int targetSum) {
	unordered_set<int> nums;
	for (int num:array) {
		int potentialMatch = targetSum - num;
		if (nums.find(potentialMatch)!=nums.end())
			return vector<int> {potentialMatch, num};
		else
			nums.insert(num);
	}
	return {};
}
// 3. sort then two pointer
// O(NlogN) time | O(1) space
vector<int> twoNumberSum3(vector<int> array, int targetSum)
{
	sort(array.begin(), array.end());
	int left=0;
	int right=array.size()-1;
	while (left<right) {
		int currentSum = array[left] + array[right];
		if (currentSum == targetSum) {
			return {array[left], array[right]};
		} else if (currentSum < targetSum) {
			left++;
		} else if (currentSum > targetSum) {
			right--;
		}
	}
	return {};
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