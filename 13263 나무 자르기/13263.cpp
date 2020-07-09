#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

int a[MAXN], b[MAXN], dp[MAXN];
int ca[MAXN], cb[MAXN], sz, p;

double cross_x(int t1, int t2) {return (double)cb[t1]-cb[t2] / ca[t2]-ca[t1];}

void insert(int a, int b)
{
	ca[sz] = a;	cb[sz] = b; sz++;
	while(sz > 2 && cross_x(sz-2, sz-1) > cross_x(sz-1, sz)) {
		ca[sz-2] = ca[sz-1];
		cb[sz-2] = cb[sz-1];
		sz--;
	}
}
long long query(int t)
{
	while() {

	}
}
int main ()
{
	int N;
	scanf("%d", &N);
	for(int i= 0;i < N; i++) scanf("%d", &a[i]);
	for(int i= 0;i < N; i++) scanf("%d", &b[i]);
	insert(b[0], 0);
	for(int i = 1;i <=N; i++) {

	}
	return 0;
}




void merge(p, q)
{
	if p.root <= q.root
		return p.addSubTree(q);
	else
		return q.addSubTree(p);

	while(!(p.end() && q.end())) {
		tree = mergeTree(p.currentTree(), q.currentTree());
	}
}