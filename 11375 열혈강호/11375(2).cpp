#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;

vector<int> task[MAXN];
bool visit[MAXN];
int res[MAXN];

bool dfs(int x)
{
	if(visit[x]) return false;
	visit[x] = true;
	for(int next : task[x]) {
		if(!res[next] || dfs(res[next])) {
			res[next] = x;
			return true;
		}
	}
	return false;
}

int main ()
{
	int N, M, T;
	int answer = 0;
	scanf("%d %d", &N, &M);
	for(int i = 1;i <= N; i++) {
		scanf("%d", &T);
		task[i].resize(T);
		while(T--) scanf("%d", &task[i][T]);
	}
	for(int i = 1; i <= N; i++){
		fill(visit+1, visit+N+2, 0);
		answer += dfs(i);
	}
	printf("%d", answer);
	return 0;
}