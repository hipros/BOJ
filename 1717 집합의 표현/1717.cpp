#include<bits/stdc++.h>
#define MAXN 1000000
int gp[MAXN+1];

int findGparent(int c, int* depth)
{
	int p = c;
	while(p != gp[p]){
		(*depth)++;
		p = gp[p];
	}
	gp[c] = p;
	return p;
}
int main ()
{
	int n, m;
	int a, b, t, deptha, depthb, para, parb;
	scanf("%d %d", &n, &m);
	for(int i = 0;i <= n; i++) gp[i] = i;

	for(;m;--m){
		scanf("%d %d %d", &t, &a, &b);
		para = findGparent(a, &deptha); parb = findGparent(b, &depthb);
		if(t == 0){
			if(deptha > depthb) gp[parb] = para;
			else gp[para] = parb;
		}
		else if(t == 1){
			if(para == parb) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}