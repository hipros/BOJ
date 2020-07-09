#pragma warning(disable:4996)
#include<cstdio>
#include<vector>
#include<queue>
#define MAXN 10000

using namespace std;

int N, M, indeg[MAXN + 1], time[MAXN + 1], visit[MAXN+1];
vector<pair<int, int> > conn[MAXN+1]; //node, time;
vector<int> parents[MAXN + 1];
priority_queue<int, vector<int>, less<int> > q;
queue<int> trace;

int main()
{
	int s, e, t, cnt = 0;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &t);
		conn[s].push_back(make_pair(e, t));
		indeg[e]++;
	}
	scanf("%d %d", &s, &e);
	q.push(s);

	while (!q.empty()) {
		int node = q.top(); q.pop();
		for (pair<int, int> n : conn[node]) {
			indeg[n.first]--;
			if (indeg[n.first] == 0) q.push(n.first);
			if (time[n.first] <= time[node] + n.second) {
				if (time[n.first] < time[node] + n.second) {
					parents[n.first].clear();
					time[n.first] = time[node] + n.second;
				}
				parents[n.first].push_back(node);
			}
		}
	}
	
	trace.push(e); visit[e] = 1;
	while (!trace.empty()) {
		int node = trace.front(); trace.pop();
		for (int t : parents[node]) {
			if(visit[t] == 0) trace.push(t);
			visit[t] = 1; 
			cnt++;
		}
	}
	printf("%d\n%d", time[e], cnt);
	system("pause");
	return 0;
}