#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  int len = array.size();
	int pt = 0;
	
	if (sequence.size() > len)
		return false;
	if (!sequence.size())
		return true;
	
	for (int i=0;i<len;i++) {
		if (array[i] == sequence[pt]) {
			pt++;
		}
		if (pt == sequence.size()) 
			return true;
	}
	
	return false;
}

// O(N) time | O(1) space
bool isValidSubsequence_ans(vector<int> array, vector<int> sequence)
{
	int arrIdx = 0;
	int seqIdx = 0;
	while (arrIdx < array.size() && seqIdx < sequence.size()) {
		if (array[arrIdx] == sequence[seqIdx])
			seqIdx++;
		arrIdx++;
	}
	return seqIdx == sequence.size();
}