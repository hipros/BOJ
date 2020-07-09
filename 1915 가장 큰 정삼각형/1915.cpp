#include<bits/stdc++.h>
#define MAXS 1001
int input[MAXS][MAXS], dp[MAXS][MAXS];

int main()
{
	int n, m, answer = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%1d", &input[i][j]);
		}
	}
	for(int i = 1;i <= n; ++i) {
		for(int j = 1;j <= m; ++j) {
			if(input[i][j] == 0) continue;
			dp[i][j] = std::min(dp[i-1][j-1], dp[i-1][j]);
			dp[i][j] = std::min(dp[i][j], dp[i][j-1]) + input[i][j];
			answer = std::max(answer, dp[i][j]);
		}
	}
	printf("%d", answer*answer);
	return 0;
}