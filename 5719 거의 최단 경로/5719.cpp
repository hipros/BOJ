#include<bits/stdc++.h>
#define MAXN 505
#define INF (int)1e8
using namespace std;
struct EDGE {
	int node;
	int val;
	EDGE() {}
	EDGE(int node, int val) : node(node), val(val) {}
};

bool operator< (EDGE a, EDGE b) {
	return a.val> b.val;
}
vector<EDGE> conn[MAXN];
int dist[MAXN][MAXN], par[MAXN][MAXN], parind[MAXN][MAXN], N;
priority_queue<EDGE> pq;

void dijk(int k)
{
	while (!pq.empty()) {

		EDGE now = pq.top(); pq.pop();
		if (dist[k][now.node] < now.val) continue;

		for (int i = 0; i < conn[now.node].size(); i++) {
			EDGE next = conn[now.node][i];

			if (dist[k][next.node] > dist[k][now.node] + next.val) {
				dist[k][next.node] = dist[k][now.node] + next.val;
				par[k][next.node] = now.node;
				parind[k][next.node] = i;
				pq.push(EDGE(next.node, dist[k][next.node]));
			}
		}
	}
}
void delEdge(int s, int m)
{
	while (m != -1) {
		int p = par[s][m];
		int ind = parind[s][m];
		if(p != -1) conn[p][ind].val = INF;
		m = p;
	}
}
int main()
{
	int M;
	while (true) {
		int S, D;
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break; 
		scanf("%d %d", &S, &D);
		for (int i = 0; i < M; i++) {
			int s, e, v;
			scanf("%d %d %d", &s, &e, &v);
			conn[s].push_back(EDGE(e, v));
		}
		for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) dist[i][j] = INF, par[i][j] = -1;
		for (int k = 0; k < N; k++) {
			pq.push(EDGE(k, 0)); dist[k][k] = 0;
			dijk(k);
		}
		int shortest = dist[S][D];
		for (int i = 0; i < N; i++) {
			if (dist[S][i] + dist[i][D] == shortest) {
				delEdge(S, i);
				delEdge(i, D);
			}
		}
		pq.push(EDGE(S, 0)); dist[N][S] = 0;
		dijk(N);
		printf("%d\n", (dist[N][D] < INF) ? dist[N][D] : -1);
		for (int i = 0; i < N; i++) conn[i].clear();

	}
	return 0;
}