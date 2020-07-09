#include<bits/stdc++.h>
#define MAXN 101
#define INF 1e9
using namespace std;

int fw[MAXN][MAXN];

int main()
{
	int N, M, s, e, v;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) fw[i][j] = (int)INF;
		fw[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &v);
		fw[s][e] = min(fw[s][e], v);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			printf("%d ", (fw[i][j] == INF) ? 0 : fw[i][j]);
		printf("\n");
	}

	return 0;
}