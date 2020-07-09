#include<bits/stdc++.h>
#define MAXN 101
using namespace std;

int main ()
{
	int N;
	long long dp[MAXN] = {0};
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		for(int j = 1;  i > 3 && j < i-3; j++){
			dp[i] = max(dp[i], dp[i-j-2] * (j+1));
		}
		dp[i] = max(dp[i], dp[i-1]+1);
	}
	printf("%lld", dp[N]);
	return 0;
}