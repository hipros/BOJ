#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;

vector<int> conn[MAXN], restaurant, sccconn[MAXN];
int atm[MAXN], dfsn[MAXN], sccgp[MAXN], n, sccnum, indg[MAXN];
unsigned int sccatm[MAXN], state[MAXN];
queue<int> q;
stack<int> s;

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
		sccgp[x] = ++sccnum;
		while (1) {
			now = s.top(); s.pop();
			if (now == x) break;
			sccgp[now] = sccgp[x];
		}
	}
	return lowlink;
}

int main()
{
	int N, M, i, a, b, S, rn;
	unsigned int answer = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) scanf("%d", &atm[i]);
	scanf("%d %d", &S, &rn);
	restaurant.resize(rn);
	for (int& t : restaurant) scanf("%d", &t);
	for (int i = 1; i <= N; i++) if (!dfsn[i]) kosaraju(i);
	for (int i = 1; i <= N; i++) sccatm[sccgp[i]] += atm[i];
	for (int i = 1; i <= N; i++) {
		for (int j : conn[i]) {
			if (sccgp[i] != sccgp[j]) {
				sccconn[sccgp[i]].push_back(sccgp[j]);
			}
		}
	}
	for(int i = 1; i <= N; i++) sort(sccconn[i].begin(), sccconn[i].end());
	for(int i = 1; i <= N; i++) sccconn[i].erase(unique(sccconn[i].begin(), sccconn[i].end()), sccconn[i].end());
	for(int i = 1; i <= N; i++) indg[i] = sccconn[i].size();
	S = sccgp[S];
	state[S] = sccatm[S];
	q.push(S);
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for(int next : sccconn[now]) {
			if(state[next] < state[now] + sccatm[next]){
				state[next] =state[now] + sccatm[next];
				q.push(next);
			}
		}
	}
	for (int i = 0; i < rn; i++) {
		answer = max(answer, state[sccgp[restaurant[i]]]);
	}
	printf("%u", answer);

	return 0;
}