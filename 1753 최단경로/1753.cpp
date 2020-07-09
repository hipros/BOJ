#include<bits/stdc++.h>
#define MAXN 20001
#define INF MAXN*11
using namespace std;

struct node {
	int ind;
	int val;
	node() {}
	node(int ind, int val) : ind(ind), val(val) {}
};
struct cmp {
	bool operator()(node a, node b) {
		return a.val > b.val;
	}
};

vector<node> conn[MAXN];
priority_queue<node, vector<node>, cmp> pq;
int dist[MAXN];

int main()
{
	int N, M, S;
	node nw;
	scanf("%d %d", &N, &M);
	scanf("%d", &S);
	for (int i = 0; i < M; i++) {
		int s;
		scanf("%d %d %d", &s, &nw.ind, &nw.val);
		conn[s].push_back(nw);
	}
	for(int i = 1; i <= N; i++) dist[i] = INF;
	pq.push(node(S, 0)); dist[S] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();
		if(dist[now.ind] < now.val) continue;
		
		for (node toward : conn[now.ind]) {
			if (dist[toward.ind] > now.val + toward.val) {
				dist[toward.ind] = now.val + toward.val;
				pq.push(node(toward.ind, now.val + toward.val));
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
	return 0;
}