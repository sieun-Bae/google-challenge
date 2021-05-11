#include <vector>
#include <algorithm>
using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights) {
  sort(redShirtHeights.begin(), redShirtHeights.end());
	sort(blueShirtHeights.begin(), blueShirtHeights.end());
	
	if (redShirtHeights[0] > blueShirtHeights[0]) {
		for (int i=0;i<redShirtHeights.size();i++) {
			if (redShirtHeights[i] < blueShirtHeights[i])
				return false;
		}
	} else if (redShirtHeights[0] < blueShirtHeights[0]){
		for (int i=0;i<redShirtHeights.size();i++) {
			if (redShirtHeights[i] > blueShirtHeights[i])
				return false;
		}
	} else {
		return false;
	}
  return true;
}
