//Binary Search

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
	if (array.size()==0)
		return -1;
	if (array.size()==1) {
		if (array[0] == target) {
			return 0;
		} else
			return -1;
	}
	
	int left = 0;
	int right = array.size()-1;
	
  	while (left<=right) {
		int mid = (left+right)/2;
		printf("%d %d %d\n", left, mid, right);
		if (array[mid] > target) {
			right = mid-1;
		} else if (array[mid] < target) {
			left = mid+1;
		} else {
			return mid;
		}
	}
	
	return -1;
}

int main()
{

	vector<int> array;
	array = {0,1,21,33,45,45,61,71,72,73};
	int target = 33;

	binarySearch(array, target);

	return 0;
}