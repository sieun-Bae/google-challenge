#include <vector>
using namespace std;

// always O(N^2) time | O(N) space
vector<int> bubbleSort(vector<int> array) {
  for (int i=0;i<array.size();i++) {
		for (int j=1;j<array.size();j++) {
			if (array[j-1] > array[j]) {
				int tmp = array[j-1];
				array[j-1] = array[j];
				array[j] = tmp;
			}
		}
	}
  return array;
}


vector<int> bubbleSort2(vector<int> array)
{
	if (array.empty())
		return {};
	
	bool isSorted = false;
	int counter = 0;
	while(!isSorted) {
		isSorted = true;
		for (int i=0;i<array.size()-1-counter;i++) {
			if (array[i]>array[i+1]) { 
				isSorted = false;
				swap(array[i], array[i+1]);
			}
		}
		counter++;
	}
  	return array;
}
