#include <iostream>
#include <string>
using namespace std;

int bitCount(int x)
{
	if (x==0)
		return 0;
	return x%2+bitCount(x/2);
}
int main() {
	string bob, alice;
	int ans=0;
	cin>>bob;
	cin>>alice;
	/*	
	uint32_t a = 0;
	char c;
	while ((c=getchar())!='\n') {
		a<<=1;
		a+=(c-'0')&1;
	}
	int b=stoi(bob, 0, 2);
	int a=stoi(alice,0,2);
	printf("%u\n", a);
	int ans = ~(b^a);
	printf("%u\n", ans);
	printf("%d\n", bitCount(ans));*/
	for (int i=0;i<bob.size();i++) {
		if (!(bob[i]-'0' ^ alice[i]-'0')) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
