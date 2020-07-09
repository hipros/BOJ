#include<cstdio>
#include<algorithm>
#define MAXN 256
using namespace std;

int winner[MAXN+1][MAXN+1], dp[MAXN+1][MAXN+1];
int N, st[MAXN+1];

int main ()
{
	scanf("%d", &N);
	for(int i = 1;i <= N; i++) scanf("%d", &st[i]);
	for(int i = 1;i <= N; i++) {
		dp[i][i] = 0;
		winner[i][i] = st[i];
	}

	for(int i = 1;i < N; ++i){
		int s = 1, e = i+1;
		for(int j = 1; j <= N-i; ++j){
			int t = 1;
			for(int k = e-s; k > 0; --k, ++t){
				if(dp[s][e] == 0 || dp[s][e] > dp[s+k][e] + dp[s][e-t] + abs(winner[s+k][e]-winner[s][e-t])){
					winner[s][e] = min(winner[s+k][e], winner[s][e-t]);
					dp[s][e] = dp[s+k][e] + dp[s][e-t] + abs(winner[s+k][e]-winner[s][e-t]);
				}
			}
			s++; e++;
		}
	}
	printf("%d", dp[1][N]);
	return 0;
}