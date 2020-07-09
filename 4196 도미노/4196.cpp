#include<bits/stdc++.h>
#define MAXN 100000
using namespace std;

int T, N, M, s, e;
int scccnt = 0, seqnum = 1;
int scccheck[MAXN+1], dfsseq[MAXN+1], sccindeg[MAXN+1];
vector<int> conn[MAXN+1];
stack<int> seqorder;


int dfs(int cur)
{
	int ret;
	dfsseq[cur] = seqnum++;
	seqorder.push(cur);
	ret = dfsseq[cur];
	for(int c : conn[cur]){
		if(dfsseq[c]==0){
			ret = min(ret, dfs(c));
		}
		else if(scccheck[c] == 0){
			ret = min(ret, dfsseq[c]);
		}
	}
	if(ret == dfsseq[cur]){
		int n;
		++scccnt;
		do{
			n = seqorder.top();seqorder.pop();
			scccheck[n] = scccnt;
		}while(n != cur);
	}
	return ret;
}

int main ()
{
	int ans;
	scanf("%d", &T);
	for(;T;--T)
	{
		ans = 0; seqnum = 1;scccnt = 0;
		scanf("%d %d", &N, &M);
		for(int k = 0;k < M; k++){
			scanf("%d %d", &s, &e);
			conn[s].push_back(e);
		}
		for(int i = 1;i <= N; i++){
			if(dfsseq[i]==0) 
				dfs(i);
		}
		for(int i = 1;i <=N; i++){
			for(int n : conn[i]){
				if(scccheck[i] != scccheck[n])
					sccindeg[scccheck[n]]++;
			}
		}
		ans = 0;
		for(int i = 1;i <= scccnt; i++){
			if(sccindeg[i]==0)
				ans++;
		}
		printf("%d\n", ans);
		for(int i = 1;i <= N; i++) {
			conn[i].clear();
			scccheck[i] = 0;
			dfsseq[i] = 0;
			sccindeg[i] = 0;
		}
	}
	return 0;
}