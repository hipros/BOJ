#include<cstdio>
#include<algorithm>
#define MAXN 202
#define MAXCOL 1e9
using namespace std;
int light[MAXN], dp[MAXN][MAXN];

int topDown(int l, int r)
{
	int &ret = dp[l][r];
	if (ret != MAXCOL) return ret;
	int left, right, t;

	for (int i = l; i < r; i++) {
		left = topDown(l, i);
		right = topDown(i + 1, r);
		t = !(light[l] == light[i + 1]);
		ret = min(ret, left + right + t);
	}
	return ret;
}
int main()
{
	int N, K, answer, w = 0;
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", light + i - w);
		w += (light[i - w] == light[i - w - 1]);
	}
	N -= w;
	for (int i = 1; i <= N; i++)
		for (int j = i+1; j <= N; j++) dp[i][j] = MAXCOL;
	answer = topDown(1, N);
	printf("%d", answer);
	return 0;
}