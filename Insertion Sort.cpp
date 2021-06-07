//Insertion Sort

#include <vector>
using namespace std;

// O(N) ~ O(N^2) time | O(N) space
vector<int> insertionSort(vector<int> array) {
  for (int idx=1;idx<array.size();idx++) {
		int tmp = array[idx];
		int prev = idx-1;
		
		while (prev>=0 && (array[prev]>tmp)) {
			array[prev+1] = array[prev];
			prev--;
		}
		array[prev+1] = tmp;
	}
  return array;
}

#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
	if (array.empty())
		return {};
	for (int i=1;i<array.size();i++) {
		int j=i;
		while (j>0 && array[j]<array[j-1]) {
			swap(array[j], array[j-1]);
			j--;
		}
	}
	return array;
}