using namespace std;

int fibo[1000];
int getNthFib(int n) {
	if (n==1) {
		return 0;
	} else if (n==2) {
		return 1;
	} else {
		fibo[0] = 0;
		fibo[1] = 1;
		for (int i=2;i<n;i++) {
			fibo[i] = fibo[i-1] + fibo[i-2];
		}
	}
	return fibo[n-1];
}

