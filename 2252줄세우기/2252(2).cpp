#include<bits/stdc++.h>
#define MAXN 32005
using namespace std;

vector<int> conn[MAXN];
int indg[MAXN];

int main ()
{
	int N, M, a, b;
	queue<int> q;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		indg[b]++;
	}
	for(int i = 1; i <= N; i++) if(indg[i]== 0) q.push(i);
	while(!q.empty()) {
		int now = q.front(); q.pop();
		printf("%d ", now);
		for(int next : conn[now]) {
			indg[next]--;
			if(indg[next] == 0) q.push(next);
		}
	}
	return 0;	
}