#include<bits/stdc++.h>
#define INF 1e9
#define MAXN 5005
using namespace std;
int num[MAXN], dp[MAXN][MAXN], p[MAXN][MAXN];

int main ()
{
	int T, N;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &num[i]);
		for(int i = 1; i <= N; i++) dp[i][i] = 0, c[i][i] = 0, c[i][i+1] = num[i]+num[i+1];
		for(int j = 2; j <= N; j++){
			for(int i = j-1; i >= 1; j--){
				dp[i][j] = INF;
				for(int k = p[i][j-1]; k <= p[i+1][j]; k++) {
					if(dp[i][j] > dp[i][k] + dp[k+1][j] + c[i][k] + c[k+1][j])
				}
			}
		}
	}
	return 0;
}