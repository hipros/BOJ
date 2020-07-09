#include<bits/stdc++.h>
#define MAXN 405
#define INF (int)1e7
using namespace std;

int net[MAXN][MAXN];

int main ()
{
	int N, K, S, s, e;
	scanf("%d %d", &N, &K);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) net[i][j] = INF;
	for(int i = 0;i < K; i++) {
		scanf("%d %d", &s, &e);
		net[s][e] = 1;
	}
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				net[i][j] = min(net[i][j], net[i][k] + net[k][j]);
			}
		}
	}
	scanf("%d", &S);
	for(int i = 0 ; i < S; i++) {
		scanf("%d %d", &s, &e);
		if(net[s][e] == INF && net[e][s] == INF) printf("0\n");
		else if(net[e][s] == INF) printf("-1\n");
		else printf("1\n");
	}
	return 0;
}