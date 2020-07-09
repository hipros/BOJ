#pragma warning(disable:4996)
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define MAXV 50005
#define MAXE 200000

struct Edge {
	int s, e;
	int val;

	bool operator< (Edge a) { return this->val < a.val; }
};
Edge ed[MAXE];
Edge MST[MAXV];
int gp[MAXV], mstedn, depth[MAXV];
pair<int, int> mstpar[MAXV];
vector<pair<int, int>> mstconn[MAXV];
queue<int> q;
queue<pair<int, int>> findmaxq;

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
	int V, E, cyclestart, cycleend, trace, maxwincycle = 0, secondw = 0, newedge = 0;
	int gpnum;
	bool ch = true;
	scanf("%d %d", &V, &E);
	gpnum = V;
	for (int i = 0; i <E; i++) scanf("%d %d %d", &ed[i].s, &ed[i].e, &ed[i].val);
	for (int i = 1; i <= V; i++) gp[i] = i;
	sort(ed, ed + E);

	for (Edge edge : ed) {
		int v1 = edge.s, v2 = edge.e;
		if (find(v1) != find(v2)) {
			Union(v1, v2);
			MST[mstedn].s = edge.s; MST[mstedn].e = edge.e; MST[mstedn++].val = edge.val;
			mstconn[edge.s].push_back(make_pair(edge.e, edge.val)); mstconn[edge.e].push_back(make_pair(edge.s, edge.val));
			secondw += edge.val;

			gpnum--;
		}
		else if (ch) {
			ch = false;
			MST[mstedn].s = edge.s; MST[mstedn].e = edge.e; MST[mstedn++].val = edge.val;
			mstconn[edge.s].push_back(make_pair(edge.e, edge.val)); mstconn[edge.e].push_back(make_pair(edge.s, edge.val));
			newedge = edge.val;

			cyclestart = edge.s; cycleend = edge.e;
		}
	}
	if (gpnum != 1) {
		printf("-1");
		return 0;
	}
	q.push(cyclestart);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (pair<int, int> next : mstconn[now]) {
			if (mstpar[next.first].first != 0) {
				mstpar[next.first].first = now;
				mstpar[next.first].second = next.second;
				q.push(next.first);
			}
		}
	}
	trace = cycleend;
	while (mstpar[trace].first != 0) {
		if (maxwincycle < mstpar[trace].second) maxwincycle = mstpar[trace].second;
		trace = mstpar[trace].first;
	}
	
	printf("%d\n", secondw - maxwincycle + newedge);
	getchar(); getchar();
	return 0;
}