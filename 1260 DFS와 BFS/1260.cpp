#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;

bool table[MAXN][MAXN], visit[MAXN];
int cnt, N, M, S;;

void dfs(int c)
{
	printf("%d ", c);
	cnt++;
	if(cnt == N) return;

	for(int i = 1; i <= N; i++){
		if(table[c][i] == 1 && !visit[i]) {
			visit[i] = 1;
			dfs(i);
		}
	}
}

int main ()
{
	queue<int> q;
	scanf("%d %d %d", &N, &M, &S);
	for(int i = 0; i < M; i++){
		int s, e;
		scanf("%d %d", &s, &e);
		table[s][e] = 1;
		table[e][s] = 1;
	}
	visit[S] = 1;
	dfs(S);
	memset(visit, 0, sizeof(bool) *(N+1));

	visit[S] = 1;
	printf("\n%d ", S);
	q.push(S);
	while(!q.empty()){
		int now = q.front(); q.pop();
		for(int i = 1; i <= N; i++) {
			if( table[now][i] && !visit[i]) {
				printf("%d ", i);
				visit[i] = 1;
				q.push(i);
			}
		}
	}
	return 0;
}