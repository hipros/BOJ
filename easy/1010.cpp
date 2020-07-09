#include<cstdio>
#define MAXN 30

int visit[MAXN+1][MAXN+1];

long long comb(int a, int b)
{
	if(a == b || b == 0) visit[a][b] = 1;
	else if(!visit[a][b]) visit[a][b] = comb(a-1, b) + comb(a-1, b-1);

	return visit[a][b];
}
int main ()
{
	int n, a, b;
	scanf("%d", &n);
	for(;n;--n){
		scanf("%d %d", &a, &b);
		printf("%lld\n", comb(b, a));
	}
	return 0;
}