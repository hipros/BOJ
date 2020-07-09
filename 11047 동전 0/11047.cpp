#include<bits/stdc++.h>
#define MAXN 15
using namespace std;

int main ()
{
	int N, K, answer = 0;
	vector<int> coin;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		if(t > K) break;
		coin.push_back(t);
	}
	
	for(int i = coin.size()-1; i>= 0; i--) {
		int c = coin[i];
		if(K == 0) break;
		answer += (K/c);
		K %= c;
	}
	printf("%d", answer);
	return 0;
}