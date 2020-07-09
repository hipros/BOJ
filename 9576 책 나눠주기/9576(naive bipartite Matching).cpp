#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;

struct stu {
	int s, e;
} st[MAXN];
int whoHas[MAXN];
bool visit[MAXN];

bool dfs(int x)
{
	visit[x] = true;
	for(int i = st[x].s; i <= st[x].e; i++) {
		int wH = whoHas[i];
		if(!wH || (!visit[wH] && dfs(wH))){
			whoHas[i] = x;
			return true;
		}
	}
	return false;
}

int main ()
{
	int T;
	scanf("%d", &T);
	while(T--){
		int N, M, answer = 0;
		scanf("%d %d", &N, &M); // N : 책수, M: 학생 수
		for(int i = 1; i <= M; i++) scanf("%d %d", &st[i].s, &st[i].e);

		for(int i = 1; i <= M; i++) {
			fill(visit+1, visit+M+2, 0);
			answer += dfs(i);
		}
		printf("%d\n", answer);
		fill(whoHas+1, whoHas+N+2, 0);
	}
	return 0;
}