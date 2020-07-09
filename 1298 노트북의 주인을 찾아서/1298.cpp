#include<bits/stdc++.h>
#define MAXN 105
using namespace std;

vector<int> mylist[MAXN];
bool visit[MAXN];
int whoLike[MAXN];

bool dfs(int x)
{
	visit[x] = true;
	for(int prefer : mylist[x]){
		int& preLike = whoLike[prefer];
		if(!preLike || (!visit[preLike] && dfs(preLike))) {
			whoLike[prefer] = x;
			return true;
		}
	}
	return false;
}

int main ()
{
	int N, M, answer = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++) {
		int s, n;
		scanf("%d %d", &s, &n);
		mylist[s].push_back(n);
	}
	for(int i = 1; i <= N; i++){
		answer += dfs(i);
		fill(visit+1, visit+ N+2, 0);
	}
	printf("%d", answer);
	return 0;
}