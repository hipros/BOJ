#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;

int N, dfsn[MAXN * 2], n, sccgp[MAXN * 2], gpnum;
vector<int> conn[MAXN * 2];
stack<int> s;
inline int convertneg(int a) { return 2*N-a-1; }

int kosaraju(int x)
{
	dfsn[x] = ++n;
	s.push(x);
	int lowlink = dfsn[x];
	for (int next : conn[x]) {
		if (!dfsn[next]) {
			lowlink = min(lowlink, kosaraju(next));
		}
		else if (!sccgp[next]) {
			lowlink = min(lowlink, dfsn[next]);
		}
	}
	if (lowlink == dfsn[x]) {
		int now;
		sccgp[x] = ++gpnum;
		while (1) {
			now = s.top(); s.pop();
			sccgp[now] = sccgp[x];
			if (now == x) break;
		}
	}
	return lowlink;
}

int main()
{
	int M, a, b, i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		if (a < 0) a = 2 * N + a;
		else a--;
		if (b < 0) b = 2 * N + b;
		else b--;
		conn[convertneg(a)].push_back(b);
		conn[convertneg(b)].push_back(a);
	}
	for (i = 1; i <= N * 2; i++) if (!dfsn[i]) kosaraju(i);
	for (i = 1; i <= N; i++) if (sccgp[i] == sccgp[convertneg(i)]) break;
	printf("%d", i == (N+1));
	return 0;
}