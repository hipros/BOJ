#include<bits/stdc++.h>
#define MAXN 500
using namespace std;

int main()
{
	int n, answer = 0;
	int dp[MAXN][MAXN] = { 0, }, input[MAXN][MAXN];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &input[i][j]);
		}
	}
	dp[0][0] = input[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + input[i][0];
		for (int j = 1; j < i; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i-1][j-1]);
			dp[i][j] += input[i][j];
		}
		dp[i][i] = dp[i - 1][i - 1] + input[i][i];
	}
	for (int i = 0; i <= n; i++) {
		answer = max(answer, dp[n-1][i]);
	}

	printf("%d", answer);
	return 0;
}