#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int M, N, K, answer = 0;
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i <= K; i++) {
		int n = N-i;
		int m = M-(K-i);
		answer = max(answer, min(n/2, m));
	}
	printf("%d", answer);
	return 0;
}