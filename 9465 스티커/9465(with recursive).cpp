#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;

int bottom(int);
int top(int);
int flat(int);

int val[2][MAXN];
int f[MAXN], t[MAXN], b[MAXN];
int visit[MAXN];

int bottom(int N)
{
	if(N == 0 || (visit[N]&1) ) return b[N];
	visit[N] |= 1;
	return b[N] = max(top(N-1) + val[1][N], flat(N-1));

}
int top(int N)
{
	if(N == 0 || visit[N]&(1<<1) ) return t[N];
	visit[N] |= (1<<1);
	return t[N] = max(bottom(N-1)+val[0][N], flat(N-1));
}
int flat(int N)
{
	if(N == 0 || visit[N]&(1<<2) ) return f[N];
	visit[N] |= (1<<2);
	return f[N] = max(bottom(N-1) + val[0][N], top(N-1) + val[1][N]);
}

int main ()
{
	int T, N;
	scanf("%d", &T);
	while(T--) {		
		scanf("%d", &N);
		for(int i = 0; i < 2; i++) for(int j = 1; j <= N; j++) scanf("%d", &val[i][j]);
		fill(visit +1, visit+N+1, 0);
		printf("%d\n", flat(N));
	}
	return 0;
}