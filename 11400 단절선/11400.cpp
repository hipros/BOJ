#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

int dfsn[MAXN], low[MAXN], n, visit[MAXN];
vector<int> conn[MAXN];
set<pair<int, int> > articalE;

void color(int x)
{
	visit[x] = true;
	for(int next : conn[x]) {
		if(visit[next]) continue;
		if(dfsn[x] < low[next]) {
			pair<int, int> p = make_pair(min(x, next), max(x, next));
			articalE.insert(p);
		}
		color(next);
	}
}
int dfs(int x, int p)
{
	low[x] = dfsn[x] = ++n;
	for(int next : conn[x]) {
		if(next == p) continue;
		if(!dfsn[next]) {
			low[x] = min(low[x], dfs(next, x));
		}
		else {
			low[x] = min(low[x], dfsn[next]);
		}
	}
	return low[x];
}
int main ()
{
	int V, E;
	scanf("%d %d", &V, &E);
	for(int i = 0;i < E; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}
	dfs(1, 0);
	color(1);
	printf("%d\n", articalE.size());
	for(pair<int, int> answer : articalE) printf("%d %d\n", answer.first, answer.second);
	return 0;
}