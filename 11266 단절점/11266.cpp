#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;

vector<int> conn[MAXN], bcc[MAXN];
int dfsn[MAXN], low[MAXN], par[MAXN], visit[MAXN], V, n, cnum;
void color(int now, int c)
{
	if (c > 0) bcc[now].push_back(c);
	visit[now] = true;
	for (int next : conn[now]) {
		if (visit[next]) continue;
		if (dfsn[now] <= low[next]) {
			bcc[now].push_back(++cnum);
			color(next, cnum);
		}
		else {
			color(next, c);
		}
	}
}
void dfs(int now, int p)
{
	low[now] = dfsn[now] = ++n;
	par[now] = p;
	for (int next : conn[now]) {
		if (next == p) continue;
		if (!dfsn[next]) {
			dfs(next, now);
			low[now] = min(low[now], low[next]);
		}
		else {
			low[now] = min(low[now], dfsn[next]);
		}
	}
}
int main()
{
	int E, a, b;
	vector<int> artical;
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) if (dfsn[i] == 0) dfs(i, -1);
	for (int i = 1; i <= V; i++) if (visit[i] == 0) color(i, 0);

	for (int i = 1; i <= V; i++) if (bcc[i].size() > 1) artical.push_back(i);
	printf("%d\n", artical.size());
	for (int i = 0; i < artical.size(); i++) printf("%d ", artical[i]);

	return 0;
}