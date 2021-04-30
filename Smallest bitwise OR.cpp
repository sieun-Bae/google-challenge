//Size of the smallest subset with maximum Bitwise OR
#include <iostream>
using namespace std;

int OR(int data[], int sz)
{
	int mOR = 0;
	for (int i=0;i<sz;i++) {
		mOR |= data[i];
	}
	return mOR;
}

void minSubset(int data[], int sz, int pos, int len, int subset[], int req, int& ans)
{
	if (len > 0 && OR(subset, len) == req && pos==sz) {
		ans = min(len, ans);
	} else if (pos<sz) {
		subset[len] = data[pos];
		minSubset(data, sz, pos+1, len+1, subset, req, ans);
		minSubset(data, sz, pos+1, len, subset, req, ans);
	}
}

int main()
{
	int data[] = {5,1,3,4,2};
	int sz = sizeof(data) / sizeof(0);

	int req = OR(data, sz);
	int ans = sz;
	int subset[sz];
	minSubset(data, sz, 0,0, subset, req, ans);
	printf("%d\n", ans);

	return 0;
}