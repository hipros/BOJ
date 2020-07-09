#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

vector<int> conn[MAXN];
int dfsn[MAXN], n, sccgp[MAXN], scccnt;
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
		sccgp[x] = ++scccnt;
		while (true) {
			int now = s.top(); s.pop();
			sccgp[now] = sccgp[x];
			if (now == x) break;
		}
	}
	return lowlink;
}

int main()
{
	int T, N, M, a, b, i;
	int indg[MAXN] = {0,} , startscc = -1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &a, &b);
			conn[a].push_back(b);
		}
		for (i = 0; i < N; i++) if (!dfsn[i]) dfs(i);
		for (i = 0; i < N; i++) {
			for (int j : conn[i]) {
				if (sccgp[i] != sccgp[j]) indg[sccgp[j]]++;
			}
		}
		for (i = 1; i <= scccnt; i++) {
			if (indg[i] == 0) {
				if (startscc == -1) startscc = i;
				else break;
			}
		}
		if (i == scccnt + 1) {
			for (int i = 0; i < N; i++) if (sccgp[i] == startscc) printf("%d\n", i);
		}
		else printf("Confused\n");

		fill(indg, indg + N + 2, 0);
		fill(dfsn, dfsn + N + 2, 0);
		fill(sccgp, sccgp + N + 2, 0);
		for (int i = 0; i < N; i++) conn[i].clear();
		n = 0; scccnt = 0; startscc = -1;
		printf("\n");
	}
	return 0;
}