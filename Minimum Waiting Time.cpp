#include <algorithm>
using namespace std;

int minimumWaitingTime(vector<int> queries) {
  sort(queries.begin(), queries.end());
	if (queries.size() == 1)
		return 0;
	
	int waitingTime = 0;
	int totalTime = 0;
	for (int i=1;i<queries.size();i++) {
		waitingTime += queries[i-1];
		totalTime += waitingTime;
	}
  return totalTime;
}
