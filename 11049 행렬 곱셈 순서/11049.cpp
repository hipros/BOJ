#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define MAX 505
int dp[MAX][MAX], row[MAX], col[MAX];

int topDown(int l, int r)
{
	int &ret = dp[l][r];
	if (ret < INF) return ret;
	if (r - l == 1) return ret = (row[l] * col[l] * col[r]);
	for (int i = l; i < r; i++) {
		ret = min(ret, row[l] * col[i] * col[r] + topDown(l, i) + topDown(i + 1, r));
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &row[i], &col[i]);
	for (int i = 1; i <n; i++) for (int j = i + 1; j <= n; j++) dp[i][j] = INF;
	printf("%d", topDown(1, n));
	return 0;
}