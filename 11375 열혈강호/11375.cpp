#include<bits/stdc++.h>
#define MAXM 1000
#define MAXN 1000
using namespace std;

vector<int> p[MAXN+1];
int assign[MAXM+1], visit[MAXN+1];

int findmatch(int cur)
{
	visit[cur] = 1;
	for(int work: p[cur]){
		if( !assign[work] || !visit[assign[work]] && findmatch(assign[work]) ) {
			assign[work] = cur;
			return 1;
		}
	}
	return 0;
}

int main ()
{
	int N, M, cnt=0;
	scanf("%d %d", &N, &M);
	for(int i = 1;i <= N; ++i){
		int t, l;
		scanf("%d", &t);
		for(int j= 0; j <t; j++){
			scanf("%d", &l);
			p[i].push_back(l);
		}
	}
	for(int i = 1;i <= N; i++){
		if(findmatch(i)) ++cnt;
		for(int j = 1;j <= N; j++) visit[j] = 0;
	}
	printf("%d", cnt);
	return 0;
}