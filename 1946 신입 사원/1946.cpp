#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
struct employ {	int r1, r2; };
bool operator< (const employ &a,const employ &b){ return a.r1 < b.r1; }
vector<employ> em;

int main ()
{
	int T, N;
	scanf("%d", &T);
	while(T--) {
		int m = MAXN+1, cnt = 0;
		scanf("%d", &N);
		em.resize(N);
		for(employ &t : em) scanf("%d %d", &t.r1, &t.r2);
		sort(em.begin(), em.end());
		for(employ &t : em) {
			if(m > t.r2) {
				cnt++;
				m = t.r2;
				if(m == 1) break;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}