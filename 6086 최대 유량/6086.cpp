#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
#define INF (int)1e9

int cost[MAXN][MAXN], flow[MAXN][MAXN], trc[MAXN];
vector<int> conn[MAXN];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char s, e;
		int val, S, E;
		scanf(" %c %c %d", &s, &e, &val);
		S = s-'A'+1; E = e-'A'+1;
		if(!cost[S][E]) conn[S].push_back(E), conn[E].push_back(S);
		cost[S][E] += val; cost[E][S] += val;
	}
	int S = 1, E = 'Z'-'A'+1, crtEdge = INF, answer = 0;
	while (true) {
		queue<int> q;
		memset(trc, 0, sizeof(int)*MAXN);
		q.push(S);
		while (!q.empty() && !trc[E]) {
			int now = q.front(); q.pop();

			for (int next : conn[now]) {
				if (trc[next] || (cost[now][next] - flow[now][next] == 0)) continue;
					trc[next] = now;
					q.push(next);
			}
		}
		if (trc[E] == 0) break;

		for (int s = E; s != S; s = trc[s]) {
			crtEdge = min(crtEdge, cost[trc[s]][s] - flow[trc[s]][s]);
		}

		for (int s = E; s != S; s = trc[s]) {
			flow[trc[s]][s] += crtEdge;
			flow[s][trc[s]] -= crtEdge;
		}
		answer += crtEdge;
	}
	printf("%d", answer);

	return 0;
}