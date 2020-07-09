#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1e9
using namespace std;
struct Edge {
	int e;
	int val;
	Edge() {}
	Edge(int e, int val): e(e), val(val) {}
};
bool operator< (Edge a ,Edge b){
	return a.val > b.val;
}

const int inf = (int)INF;
int dist[MAXN];
vector<Edge> conn[MAXN];
priority_queue<Edge, vector<Edge> > pq;

int main ()
{
	Edge t;
	int N, M, s, S, E;
	scanf("%d \n%d", &N, &M);
	for(int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &t.e, &t.val);
		conn[s].push_back(t);
	}
	scanf("%d %d", &S, &E);
	pq.push(Edge(S, 0));
	fill(dist+1, dist+N+2, inf); dist[S] = 0;

	while(!pq.empty()) {
		Edge now = pq.top(); pq.pop();
		if(now.val > dist[now.e]) continue;
		for(Edge to : conn[now.e]) {
			if(dist[to.e] > to.val + now.val) {
				dist[to.e] = to.val + now.val;
				pq.push(Edge(to.e, dist[to.e]));
			}
		}
	}
	printf("%d", dist[E]);
	return 0;
}