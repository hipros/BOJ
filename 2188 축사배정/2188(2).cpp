#include<bits/stdc++.h>
#define MAXN 205
using namespace std;

vector<int> conn[MAXN];
bool visit[MAXN] = {true, };
int exist[MAXN];

bool dfs(int x)
{
	if(visit[x]) return false;
	visit[x] = true;
	for(int &next : conn[x]) {
		if(!exist[next] || dfs(exist[next])) {
			exist[next] = x;
			return true;
		}
	}
	return false;
}

int main ()
{
	int N, M, answer = 0, T;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &T);
		conn[i].resize(T);
		while(T--) scanf("%d", &conn[i][T]);
	}
	for(int i = 1; i <= N; i++) {
		fill(visit+1, visit+N+2, 0);
		answer += dfs(i);
	}
	printf("%d", answer);
	return 0;
}