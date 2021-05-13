#include <vector>
#include <algorithm>
using namespace std;

// O(NlogN) + O(N) + O(N) = O(NlogN) time | O(1) space
int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
  sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
	sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
	int r_s=0, r_e=redShirtSpeeds.size()-1, b_s=0, b_e=blueShirtSpeeds.size()-1;
	int tandemSpeed = 0;
	if (fastest) {
		for (int i=0;i<redShirtSpeeds.size();i++){
			if (redShirtSpeeds[r_e] > blueShirtSpeeds[b_e]) {
				tandemSpeed += redShirtSpeeds[r_e];
				r_e--;
				b_s++;
			} else if (redShirtSpeeds[r_e] < blueShirtSpeeds[b_e]) {
				tandemSpeed += blueShirtSpeeds[b_e];
				b_e--;
				r_s++;
			} else { //if max speeds are same..
				if (redShirtSpeeds[r_s] > blueShirtSpeeds[b_s]) {
					tandemSpeed += redShirtSpeeds[r_e];
					b_s++;
					r_e--;
				} else {
					tandemSpeed += blueShirtSpeeds[b_e];
					r_s++;
					b_e--;
				}
			}
		}
	} else {
		for (int i=0;i<redShirtSpeeds.size();i++) {
			tandemSpeed += max(redShirtSpeeds[i], blueShirtSpeeds[i]);
		}
	}
  return tandemSpeed;
}
