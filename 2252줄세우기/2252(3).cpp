#pragma warning(disable:4996)
#include<cstdio>
#include<vector>
#include<stack>

#define MAXN 32000

using namespace std;

int N, M, s, e;
int deg[MAXN+1];
int visit[MAXN+1];
vector<int> conn[MAXN+1];
stack<int> path;

void dfs(int node)
{
	visit[node] = 1;
	if (conn[node].size() == 0) return;
	for (int n : conn[node]) {
		if (visit[n] == 0) {
			dfs(n);
			path.push(n);
		}
	}
	while (!path.empty()) {
		if (path.top() != 0) printf("%d ", path.top());
		path.pop();
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		conn[e].push_back(s);
		deg[s]++;
	}
	for (int i = 1; i <= N; i++)
		if (deg[i] == 0)
			conn[0].push_back(i);

	dfs(0);

	system("pause");
	return 0;
}