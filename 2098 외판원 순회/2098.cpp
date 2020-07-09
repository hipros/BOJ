#include<bits/stdc++.h>
#define MAXVST 65537
#define MAXN 17
#define INF 1e9
using namespace std;
int dp[MAXN][MAXVST], w[MAXN][MAXN], N;

int tsp(int cur, int visit)
{
	if (visit == (1 << N) - 1 ){
		if(w[cur][0]) return w[cur][0];
		else return INF;
	}
	int &ret = dp[cur][visit];
	if (ret < INF) return ret;

	for (int next = 0; next < N; next++) {
		if ((visit & (1 << next)) || w[cur][next] == 0) continue;
		ret = min(ret, tsp(next, visit | (1 << next) ) + w[cur][next]);
	}
	return ret;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &w[i][j]);

	for (int i = 0; i < N; i++) for (int j = 0; j < MAXVST; j++) dp[i][j] = INF;
	printf("%d", tsp(0, 1));

	return 0;
}