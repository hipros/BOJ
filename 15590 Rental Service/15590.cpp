#include<bits/stdc++.h>
using namespace std;
struct GC { long long g, c; };

vector<long long> c, r;
vector<GC> gc;

int main()
{
	int N, M, R, t, gcn = 0;
	long long dpr = 0, maxp = 0;
	cin >> N>> M>> R;
	c.resize(N); gc.resize(M); r.resize(R);

	for (int i = 0; i < N; i++) cin >> c[i];
	for (int i = 0; i < M; i++) cin >> gc[i].g >> gc[i].c;
	for (int i = 0; i < R; i++) cin >> r[i];

	sort(c.begin(), c.end());
	sort(gc.begin(), gc.end(), [](const GC& a, const GC& b) { return a.c > b.c; });
	sort(r.begin(), r.end(), [](const int& a, const int& b)	{ return a > b;	});

	for (t = 0; t < R && t < N; t++) dpr += r[t];
	for (int i = t; i < N && gcn < M; i++) {
		while (gcn < M) {
			dpr += (gc[gcn].c * min(c[i], gc[gcn].g));
			if (c[i] < gc[gcn].g) break;
			c[i] -= gc[gcn++].g;
		}
		gc[gcn].g -= c[i];
	}

	maxp = dpr;
	for (int i = t-1; i >= 0 && gcn < M; i--) {
		dpr -= r[i];
		while (gcn < M) {
			dpr += (gc[gcn].c * min(c[i], gc[gcn].g));
			if (c[i] < gc[gcn].g) break;
			c[i] -= gc[gcn++].g;
		}
		gc[gcn].g -= c[i];
		maxp = max(maxp, dpr);
	}

	cout << maxp;
	return 0;
}