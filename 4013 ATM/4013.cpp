#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;

int scccheck[MAXN], dfsseq[MAXN], seqnum, sccnum, w[MAXN], sccw[MAXN], sccdp[MAXN];
vector<int> conn[MAXN], scc[MAXN], sccconn[MAXN], sccindeg, E;
stack<int> seq;
queue<int> q;

int dfs(int cur)
{
	int ret;
	++seqnum;
	dfsseq[cur] = seqnum;
	seq.push(cur);
	ret = seqnum;
	for (int n : conn[cur]) {
		if (dfsseq[n] == 0)
			ret = min(ret, dfs(n));
		else if (scccheck[n] == 0)
			ret = min(ret, dfsseq[n]);
	}
	if (ret == dfsseq[cur]) {
		++sccnum;
		while (1) {
			int n = seq.top(); seq.pop();
			scc[sccnum - 1].push_back(n);
			scccheck[n] = sccnum;
			if (n == cur) break;
		}
	}
	return ret;
}
int main()
{
	int N, M, S, EN, s, e, startscc, ans = -1;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		conn[s].push_back(e);
	}
	for (int i = 1; i <= N; i++) scanf("%d", &w[i]);
	scanf("%d %d", &S, &EN);
	E.assign(EN + 1, 0);
	for (int i = 1; i <= EN; i++) scanf("%d", &E[i]);

	for (int i = 1; i <= N; i++)
		if (dfsseq[i] == 0)
			dfs(i);

	startscc = scccheck[S];

	for (int i = 1; i <= N; i++) {
		sccw[scccheck[i]] += w[i];
		for (int n : conn[i]) {
			if (scccheck[i] != scccheck[n]) {
				sccconn[scccheck[i]].push_back(scccheck[n]);
			}
		}
	}

	sccindeg.assign(sccnum + 1, 0);
	for (int i = 1; i <= sccnum; i++){
		sort(sccconn[i].begin(), sccconn[i].end());
		sccconn[i].erase(unique(sccconn[i].begin(), sccconn[i].end()), sccconn[i].end());
		for (int j : sccconn[i]) sccindeg[j]++;
	}

	sccdp[startscc] = sccw[startscc];
	for(int i = startscc; i>=1; --i){
		for(int j : sccconn[i]){
			sccdp[j] = max(sccdp[j], sccdp[i]+sccw[j]);
		}
	}

	for (int i = 1; i <= EN; i++)
		ans = max(ans, sccdp[scccheck[E[i]]]);
	printf("%d", ans);
	return 0;
}