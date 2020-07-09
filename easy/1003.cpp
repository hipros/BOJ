#include<cstdio>
#define MAXN 40
int main ()
{
	int T, n;
	int dp[MAXN+1][2]={{1,0}, {0,1}, };
	for(int i = 2;i <= 40; i++){
		dp[i][0] = dp[i-1][0] + dp[i-2][0];
		dp[i][1] = dp[i-1][1] + dp[i-2][1];
	}
	scanf("%d", &T);
	for(;T; T--){
		scanf("%d", &n);
		printf("%d %d\n", dp[n][0], dp[n][1]);
	}
	return 0;
}