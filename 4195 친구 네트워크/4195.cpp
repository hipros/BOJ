#include<bits/stdc++.h>
#define MAXN 100005
#define MAXL 22
using namespace std;

map<string, int> nametable;
int gp[MAXN], hmany[MAXN], num;

int find(int x)
{
	if (gp[x] == x) return x;
	return gp[x] = find(gp[x]);
}
int Union(int p, int q)
{
	int pp = find(p), pq = find(q);
	if(pp != pq) {
		gp[pp] = gp[pq];
		hmany[pq] += hmany[pp];
	}
	return (hmany[pp]>hmany[pq]) ? hmany[pp]:hmany[pq];
}
void uptable(string t)
{
	if (nametable.find(t) == nametable.end()) {
		nametable[t] = num;
		gp[num] = num;
		hmany[num++] = 1;
	}
}
int main()
{
	int T, n, num = 0;
	char n1[MAXL], n2[MAXL];
	string t;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s %s", n1, n2);
			uptable(n1); uptable(n2);
			printf("%d\n", Union(nametable.find((string)n1)->second, nametable.find((string)n2)->second));
		}
		for (int i = 0; i < num; i++) hmany[i] = 0;
		nametable.clear();
	}
	return 0;
}