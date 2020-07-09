#include<bits/stdc++.h>
#define MAXN 505
#define INF (int)1e4
using namespace std;

const int inf = INF;
bool dist[MAXN][MAXN];
vector<int> conn[MAXN];
queue<int> q;
int main()
{
	int N, M, s, e, answer = 0, j;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		conn[s].push_back(e);
	}
	for (int k = 1; k <= N; k++) {
		q.push(k);
		dist[k][k] = true;
		while (!q.empty()) {
			int now = q.front(); q.pop();
			for (int next : conn[now]) {
				if (dist[k][next]) continue;
				dist[k][next] = true;
				dist[next][now] = true;
				dist[next][k] = true;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (j = 1; j <= N && dist[i][j]; j++) ;
		if (j == N+1) answer++;
	}
	printf("%d", answer);
	return 0;
}