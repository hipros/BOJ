#include<bits/stdc++.h>
#define MAXM 1000005
#define MAXN 100005
using namespace std;
struct edge {
	int val, s, e;
	bool operator< (edge a) {return this->val < a.val;}
};
edge ed[MAXM];
int gp[MAXN];

int find(int x) 
{
	if(gp[x] == x) return x;
	return gp[x] = find(gp[x]);
}
void Union(int p, int q)
{
	gp[find(p)] = gp[find(q)];
}
int main ()
{
	int N, M, gpnum, mst = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++) scanf("%d %d %d", &ed[i].s, &ed[i].e, &ed[i].val);
	for(int i = 1; i <= N; i++) gp[i] = i;
	gpnum = N;
	sort(ed, ed+M);
	for(int i = 0; i < M && gpnum > 2; i++) {
		if(find(ed[i].s) != find(ed[i].e)){
			mst += ed[i].val; gpnum--;
			Union(ed[i].s, ed[i].e);
		}
	}
	printf("%d", mst);
	return 0;
}