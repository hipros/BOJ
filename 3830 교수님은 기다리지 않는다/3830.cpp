#include<bits/stdc++.h>
#define MAXN 100005
int w[MAXN], gp;

int main ()	
{
	char t;
	int N, M, a, b, c;
	while(true) {
		scanf("%d %d", &N, &M);
		if(N==0 && M==0) break;
		scanf("%c %d %d %d", &t, &a, &b);
		if(t == '!'){
			scanf("%d", &c);

		}
		else if(t == '?') {
			printf("%d\n", w[a]-w[b]);
		}
	}
	return 0;
}
