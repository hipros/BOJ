#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;

int dp[2][MAXN][MAXN];
int card[MAXN];

int DP(int l, int r, int t)
{
	int t1, t2;
	int &ret = dp[t][l][r];
	if (ret) return ret;
	if (l == r) return (t == 0) ? card[l] : 0;

	t1 = DP(l + 1, r, t ^ 1); t2 = DP(l, r - 1, t ^ 1);

	if (t == 0) ret = max(t1 + card[l], t2 + card[r]);
	else ret = min(t1, t2);

	return ret;
}
int main()
{
	int T, N, answer;
	scanf("%d", &T);
	while (T--) {
		answer = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) scanf("%d", card + i);
		answer = DP(0, N - 1, 0);
		printf("%d\n", answer);
		for (int i = 0; i < N; i++) {
			memset(dp[0][i], 0, sizeof(int) * N);
			memset(dp[1][i], 0, sizeof(int) * N);
		}
	}
	return 0;
}