#include<cstdio>
#include<algorithm>

#define MAXN 1000

int main ()
{
	int n, answer = 1000*1000;
	int RGB[MAXN+1][3],dp[MAXN+1][3];

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 0;j < 3; j++){
			scanf("%d", &RGB[i][j]);
		}
	}
	for(int i = 1;i <= n; i++){
		for(int j = 0;j < 3; j++){
			dp[i][j] = std::min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + RGB[i][j];
		}
	}
	for(int i = 0;i < 3; i++)
		answer = std::min(answer, dp[n][i]);
	
	printf("%d", answer);
	return 0;
}