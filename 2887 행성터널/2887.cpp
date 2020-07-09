#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
struct dot {
	int index;
	int val;
	bool operator< (dot a) { return this->val < a.val; }
};
struct edge {
	int n1, n2;
	int val;
	bool operator< (edge a) { return this->val < a.val; }
};
dot x[MAXN], y[MAXN], z[MAXN];
int gp[MAXN];
edge ed[MAXN * 3];

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
	int N, gpnum, idxx = 1, idxy = 1, idxz = 1, h = 0;
	long long w = 0;
	scanf("%d", &N);
	gpnum = N;
	for (int i = 0; i < gpnum; i++) gp[i] = i;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &x[i].val, &y[i].val, &z[i].val);
		x[i].index = i; y[i].index = i; z[i].index = i;
	}
	sort(x, x + N); sort(y, y + N); sort(z, z + N);
	for (int i = 1; i < N; i++) {
		ed[(i-1) * 3].val = x[i].val - x[i - 1].val; ed[(i - 1) * 3].n1 = x[i].index; ed[(i - 1) * 3].n2 = x[i - 1].index;
		ed[(i - 1) * 3 + 1].val = y[i].val - y[i - 1].val; ed[(i - 1) * 3 + 1].n1 = y[i].index; ed[(i - 1) * 3 + 1].n2 = y[i - 1].index;
		ed[(i - 1) * 3 + 2].val = z[i].val - z[i - 1].val; ed[(i - 1) * 3 + 2].n1 = z[i].index; ed[(i - 1) * 3 + 2].n2 = z[i - 1].index;
	}
	sort(ed, ed + 3 * N);
	while (gpnum>1) {
		if (find(ed[h].n1) != find(ed[h].n2)) {
			w += ed[h].val;
			gpnum--;
			Union(ed[h].n1, ed[h].n2);
		}
		h++;
	}
	printf("%lld", w);

	return 0;
}