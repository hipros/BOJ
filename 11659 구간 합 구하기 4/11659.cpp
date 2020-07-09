#include<bits/stdc++.h>
#define MAXN 100000

int main ()
{
	int n, m, s, e;
	int num[MAXN], sum[MAXN];
	scanf("%d %d", &n, &m);
	for(int i = 0;i < n; ++i) 
		scanf("%d", &num[i]);
	for(int i = 1;i <= n; ++i) 
		sum[i] = sum[i-1] + num[i-1];

	for(int i = 0;i < m; ++i){
		scanf("%d %d", &s, &e);
		if(s > e) std::swap(s, e);
		printf("%d\n", sum[e] - sum[s-1]);
	}
	return 0;
}