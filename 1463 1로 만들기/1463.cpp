#include<bits/stdc++.h>
using namespace std;
const int MAXN = (1e6)+5, INF = 2e9;
int N, dp[3*MAXN];

int main()
{
	cin>> N;
	fill(dp, dp+(3*N+1), INF);

	dp[N] = 0;
	for(int i = N-1; i>= 1; i--) {
		dp[i] = min(dp[i+1], min(dp[i*2], dp[i*3]))+1;
	}
	cout<<dp[1];
	return 0;
}