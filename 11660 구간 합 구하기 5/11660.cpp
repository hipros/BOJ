#include<bits/stdc++.h>
#define MAXN 1025
int mat[MAXN][MAXN], dp[MAXN][MAXN];

int main ()
{
	int n, m;	
	int sx, sy, ex, ey;

	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; ++i){
		for(int j = 1;j <= n; ++j){
			scanf("%d", &mat[i][j]);
		}
	}
	for(int i = 1;i <= n; ++i){
		for(int j = 1;j <= n; ++j) {
			dp[i][j] = mat[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}
	for(int i = 0; i < m; ++i){
		scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
		printf("%d\n", dp[ex][ey] - dp[sx-1][ey] - dp[ex][sy-1] + dp[sx-1][sy-1]);
	}
	return 0;
}