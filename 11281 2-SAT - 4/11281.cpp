#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;

vector<int> conn[MAXN*2];
int dfsn[MAXN*2], sccgp[MAXN*2], n, sccnum, N;
stack<int> s;
int negx(int x) {return 2*N-1-x;}
int kosaraju(int x)
{
	dfsn[x] = ++n;
	s.push(x);
	int lowlink = dfsn[x];
	for(int next : conn[x]) {
		if(!dfsn[next]) {
			lowlink = min(lowlink, kosaraju(next));
		}
		else if(!sccgp[next]) {
			lowlink = min(lowlink, dfsn[next]);
		}
	}
	if(lowlink == dfsn[x]) {
		int now;
		sccgp[x] = ++sccnum;
		while(1) {
			now = s.top(); s.pop();
			if(now == x) break;
			sccgp[now] = sccgp[x];
		}
	}
	return lowlink;
}

int main ()
{
	int M, a, b, i;
	scanf("%d %d", &N, &M);
	for(i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		if(a < 0) a = 2*N+a;
		else a--;
		if(b < 0) b = 2*N+b;
		else b--;
		conn[negx(a)].push_back(b);
		conn[negx(b)].push_back(a);
	}
	for(i = 0; i < 2*N; i++) if(!dfsn[i]) kosaraju(i);
	for(i = 0; i < N; i++) if(sccgp[i] == sccgp[negx(i)]) break;
	if(i != N) printf("0");
	else {
		printf("1\n");
		for(int i = 0; i < N; i++) printf("%d ", !(sccgp[i] > sccgp[negx(i)]));
	}
	return 0; 
}