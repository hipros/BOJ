#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;

struct edge {
	int s, e, v;
};
queue<edge> q;
vector<edge> ed[MAXN];
int dp[MAXN];

int maxDist(int start)
{
	for (edge node : ed[start]) {
		q.push(node);
		dp[node.e] = node.v;
	}
	while (!q.empty()) {
		edge p = q.front(); q.pop();
		for (edge next : ed[p.e]) {
			if (dp[next.e] != 0) continue;
			dp[next.e] = dp[next.s] + next.v;
			q.push(next);
		}
	}
	int maxv = 0, w = 1;
	for (int i = 1; i < MAXN; i++) {
		if (dp[i] > maxv) {
			maxv = dp[i];
			w = i;
		}
	}
	return w;
}

int main()
{
	int N, i, start, end;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &start);
		while (true) {
			edge t;
			scanf("%d", &t.e);
			if (t.e == -1) break;
			scanf("%d", &t.v);
			t.s = start;
			ed[start].push_back(t);
		}
	}
	dp[start] = -1;
	end = maxDist(start);
	memset(dp, 0, sizeof(int)*MAXN); dp[end] = -1;
	start = maxDist(end);

	if (end == start) printf("%d", dp[start]);
	else {
		memset(dp, 0, sizeof(int)*MAXN); dp[start] = -1;
		end = maxDist(start);
		printf("%d", dp[end]);
	}
	return 0;
}