#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;

struct stu {
	int s, e;
} st[MAXN];
int whoHas[MAXN], nextBlank[MAXN];
bool visit[MAXN];

int moveToBlank(int x, int endline)
{
	if (x > endline) return -1;
	if (nextBlank[x] == x) {
		nextBlank[x] = x + 1;
		return x;
	}
	int t = moveToBlank(nextBlank[x], endline);
	if (t != -1 ) nextBlank[x] = t + 1;
	return t;
}

bool dfs(int x)
{
	if (visit[x]) return false;
	visit[x] = true;

	int i = moveToBlank(st[x].s, st[x].e);
	if (i != -1) {
		whoHas[i] = x;
		return true;
	}
	for (int i = st[x].s; i <= st[x].e; i++) {
		if (dfs(whoHas[i])) {
			whoHas[i] = x;
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M, answer = 0;
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= M; i++) scanf("%d %d", &st[i].s, &st[i].e);
		for (int i = 1; i <= N; i++) nextBlank[i] = i;
		for (int i = 1; i <= M; i++) {
			fill(visit + 1, visit + M + 2, 0);
			answer += dfs(i);
		}
		printf("%d\n", answer);
		fill(whoHas+1, whoHas+N+2, 0);
	}
	return 0;
}