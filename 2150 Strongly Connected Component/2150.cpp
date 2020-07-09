#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;

bool inscc[MAXN];
int dfsn[MAXN], finished[MAXN], n;
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
		else if (!inscc[next]) {
			lowlink = min(lowlink, dfsn[next]);
		}
	}
	if (lowlink == dfsn[x]) {
		scc.push_back(vector<int>());
		while (true) {
			int now = s.top(); s.pop();
			inscc[now] = true;
			scc[scc.size() - 1].push_back(now);
			if (now == x) break;
		}
	}
	return lowlink;
}

int main()
{
	int V, E, a, b;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
	}
	for (int i = 1; i <= V; i++) if (!dfsn[i]) dfs(i);
	for (int i = 0; i < scc.size(); i++) sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end(), [](vector<int> &a, vector<int> &b) {
		return a[0] < b[0];
	});
	printf("%d\n", scc.size());
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			printf("%d ", scc[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}