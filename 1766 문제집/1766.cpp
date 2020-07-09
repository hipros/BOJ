#include<bits/stdc++.h>
#define MAXN 32005
using namespace std;

vector<int> conn[MAXN];
priority_queue<int, vector<int>, greater<int> > pq;
int indg[MAXN];

int main ()
{
	int N, M, a, b;
	scanf("%d %d", &N, &M);
	for(int i = 0;i < M; i++) {
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		indg[b]++;
	}
	for(int i = 1; i <= N; i++)	if(!indg[i]) pq.push(i);

	while(!pq.empty()) {
		int now = pq.top(); pq.pop();
		printf("%d ", now);
		for(int next : conn[now]){
			indg[next]--;
			if(!indg[next]) pq.push(next);
		}
	}
	return 0;
}