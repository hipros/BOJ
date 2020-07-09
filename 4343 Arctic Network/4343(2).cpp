#include<bits/stdc++.h>
using namespace std;
#define MAXN 505

struct outpost {
	int x, y;
	long long dist(outpost a) { return (a.x - this->x)*(a.x - this->x) + (a.y - this->y)*(a.y - this->y); }
};
struct edge {
	long long dist;
	int s, e;
	bool operator< (edge a) { return this->dist < a.dist; }
	bool operator> (edge a) { return this->dist > a.dist; }
};
outpost op[MAXN];
edge ed[MAXN*(MAXN - 1) / 2];
int gp[MAXN];

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
	int T, gpnum;
	edge answer;
	scanf("%d", &T);
	while (T--) {
		int S, P, ednum = 0;
		scanf("%d %d", &S, &P);
		gpnum = P;
		for (int i = 0; i < P; i++) scanf("%d %d", &op[i].x, &op[i].y);
		for (int i = 0; i < gpnum; i++) gp[i] = i;
		for (int i = 0; i < P; i++) {
			for (int j = i + 1; j < P; j++) {
				ed[ednum].s = i; ed[ednum].e = j;
				ed[ednum++].dist = op[i].dist(op[j]);
			}
		}
		sort(ed, ed + ednum);

		for (edge t : ed) {
			if (find(t.s) == find(t.e)) continue;
			Union(t.s, t.e);
			gpnum--;
			answer = t;
			if (gpnum == S) break;
		}
		printf("%.2f\n", sqrt(answer.dist));
	}

	return 0;
}