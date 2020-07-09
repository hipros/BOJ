#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

int dfsn[MAXN], sccgp[MAXN], n;
vector<vector<int> > scc;
vector<int> conn[MAXN];
stack<int> s;

int dfs(int x)
{
	dfsn[x] = ++n;
	s.push(x);
	int lowlink = dfsn[x];
	for (int next : conn[x]) {
		if (!dfsn[next]) {
			lowlink = min(lowlink, dfs(next));
		}
		else if (!sccgp[next]) {
			lowlink = min(lowlink, dfsn[next]);
		}
	}
	if (lowlink == dfsn[x]) {
		scc.push_back(vector<int>());
		sccgp[x] = scc.size();
		while (1) {
			int now = s.top(); s.pop();
			sccgp[now] = sccgp[x];
			scc[sccgp[x] - 1].push_back(now);
			if (now == x) break;
		}
	}
	return lowlink;
}

int main()
{
	int T, indg[MAXN] = { 0, }, answer = 0;
	scanf("%d", &T);
	while (T--) {
		int V, E, a, b;
		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &a, &b);
			conn[a].push_back(b);
		}
		for (int i = 1; i <= V; i++) if (!dfsn[i]) dfs(i);
		for (int i = 1; i <= V; i++) {
			for (int j : conn[i]) {
				if (sccgp[i] != sccgp[j]) {
					indg[sccgp[j]]++;
				}
			}
		}
		for (int i = 0; i < scc.size(); i++) if (!indg[i]) answer++;
		printf("%d\n", answer);

		for (int i = 0; i < scc.size(); i++) scc[i].clear();
		scc.clear(); answer = 0; n = 0;
		fill(indg + 1, indg + V + 2, 0);
		fill(dfsn + 1, dfsn + V + 2, 0);
		fill(sccgp + 1, sccgp + V + 2, 0);
		for (int i = 1; i <= V; i++) conn[i].clear();
	}
	return 0;
}