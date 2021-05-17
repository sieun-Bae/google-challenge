#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  for (int i=0;i<array.size();i++) {
		int idxMin = i;
		for (int j=idxMin;j<array.size();j++) {
			if (array[j] < array[idxMin])
				idxMin = j;
		}
		swap(array[i], array[idxMin]);
	}
  return array;
}

