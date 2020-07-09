#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
int gp[MAXN];
struct edge {
	int val, s, e;
	bool operator< (edge a) { return this->val < a.val; }
};
edge ed[MAXN];

int find(int x)
{
	if (gp[x] == x) return x;
	return gp[x] = find(gp[x]);
}
void Union(int p, int q)
{
	gp[find(p)] = gp[find(q)];
}
int main()
{
	while (true) {
		int N, M, sum = 0, mst = 0;
		scanf("%d %d", &M, &N);
		if (N == 0 && M == 0) break;
		for (int i = 0; i < N; i++) scanf("%d %d %d", &ed[i].s, &ed[i].e, &ed[i].val), sum += ed[i].val;
		for (int i = 0; i < M; i++) gp[i] = i;
		sort(ed, ed + N);
		for (int i = 0; i < N; i++) {
			if (find(ed[i].s) != find(ed[i].e)) {
				mst += ed[i].val;
				Union(ed[i].s, ed[i].e);
			}
		}
		printf("%d\n", sum - mst);
	}

	return 0;
}