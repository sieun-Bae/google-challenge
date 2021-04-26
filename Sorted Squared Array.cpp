#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//O(NlogN) time | O(N) space
vector<int> sortedSquaredArray(vector<int> array) {
 	vector<int> answer;
	for (int i=0;i<array.size();i++) {
		answer.push_back(array[i]*array[i]);
	}
	sort(answer.begin(), answer.end());
	return answer;
}

//O(N) time | O(N) space
vector<int> sortedSquaredArray(vector<int> array) {
	vector<int> sortedSquares(array.size(), 0);
	int smallerIdx = 0;
	int largerIdx = array.size()-1;

	for (int idx=array.size()-1; idx>=0; idx--) {
		int smallerValue = array[smallerIdx];
		int largerValue = array[largerIdx];

		if (abs(smallerValue) > abs(largerValue)) {
			sortedSquares[idx] = smallerValue * smallerValue;
			smallerIdx++;
		} else {
			sortedSquares[idx] = largerValue * largerValue;
			largerIdx--;
		}
	}
	return sortedSquares;
}