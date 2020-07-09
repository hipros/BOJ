#include<bits/stdc++.h>
using namespace std;
int N, C[1005], dp[1001][1001];

int main ()
{
	cin>> N;
	for(int i = 1; i <= N; i++) cin>>C[i];
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(j >= i) dp[i][j] = max(dp[i-1][j], dp[i][j-i] + C[i]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[N][N];
	return 0;
}