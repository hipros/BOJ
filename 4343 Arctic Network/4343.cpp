#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
struct dist
{
	long long len;
	int s, e;

	bool operator< (dist a) { return this->len < a.len; }
	bool operator> (dist a) { return this->len > a.len; }
};
struct xy
{
	int x, y;
	long long dist(xy a) { return (a.x - this->x)*(a.x - this->x) + (a.y - this->y)*(a.y - this->y); }
};
bool cantGp[MAXN][MAXN];
xy outpost[MAXN];
int whereisit[MAXN];
vector<dist> edge;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int S, P, gpnum, i;
		scanf("%d %d", &S, &P);
		for (i = 0; i < P; i++) scanf("%d %d", &outpost[i].x, &outpost[i].y);
		for (i = 0; i < P; i++) whereisit[i] = 0;
		for (i = 0; i < P; i++) {
			for (int j = i + 1; j <P; j++) {
				dist t;
				t.len = outpost[i].dist(outpost[j]);
				t.s = i; t.e = j;
				edge.push_back(t);
			}
		}
		sort(edge.begin(), edge.end(), [](dist &a, dist &b) {
			return a.len > b.len;
		});
		for (dist ed : edge) {
			int op1 = ed.s, op2 = ed.e, i, t;
			cantGp[op1][op2] = true, cantGp[op2][op1] = true;
			if (whereisit[op1] != whereisit[op2]) continue;
			for (t = whereisit[op2] + 1; t < S; t++) {
				for (i = 0; i < P; i++) {
					if (whereisit[i] == t && cantGp[i][op2]) break;
				}
				if (i == P) {
					whereisit[op2] = t;
					break;
				}
			}
			if (t == S ) break;
		}
		dist ed;
		gpnum = P;
		for (i = P * (P - 1) / 2 - 1; i >= 0 && gpnum != S; i--) {
			ed = edge[i];
			if (whereisit[ed.s] != whereisit[ed.e]) continue;
			gpnum--;
		}
		printf("%.2f\n", sqrt(ed.len));

		edge.clear();
		memset(cantGp, 0, sizeof(bool) * MAXN * MAXN);
		memset(whereisit, 0, sizeof(int) * MAXN);
	}

	return 0;
}