#include<bits/stdc++.h>
#define MAXN 10001
#define MOD 1000000007
using namespace std;

long long dp[2][MAXN], tem[MAXN];

int main()
{
	int N, i, t = 0, start = 0, j;
	long long temp;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", tem + i);
	for (i = 1; i <= N && (tem[i] == -1 || tem[i] < i); i++);

	dp[t ^ 1][0] = (i > N) ? 1 : 0;

	for (i = 1; i < N; i++, t ^= 1) {
		dp[t][0] = (dp[t ^ 1][0] + dp[t ^ 1][1]) % MOD;
		for (j = 1; j <= N; j++)
			dp[t][j] = (dp[t ^ 1][j - 1] + dp[t ^ 1][j] + dp[t ^ 1][j + 1]) % MOD;
		if (tem[i + 1] != -1) {
			temp = dp[t][tem[i + 1]];
			memset(dp[t], 0, sizeof(int)*N);
			dp[t][tem[i + 1]] = temp;
		}
	}
	printf("%lld", dp[t^1][0]);
}