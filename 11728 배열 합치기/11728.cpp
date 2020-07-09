#include<bits/stdc++.h>
#define MAXN 1000000
using namespace std;

int s1[MAXN], s2[MAXN];

int main ()
{
	int N, M, i, j, t;
	
	scanf("%d %d", &N, &M);
	for(i = 0;i < N; i++) scanf("%d", &s1[i]);
	for(i = 0;i < M; i++) scanf("%d", &s2[i]);

	for(i = 0, j = 0;i < N&&j <M;){
		if(s1[i]<s2[j]) t = s1[i++];
		else t = s2[j++];
		printf("%d ", t);
	}
	for(;i < N; i++) printf("%d ", s1[i]);
	for(;j < M; j++) printf("%d ", s2[j]);
	return 0;
}