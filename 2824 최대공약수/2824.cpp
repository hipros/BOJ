#include<bits/stdc++.h>
#define MAXN 1001
using namespace std;

multiset<int> ap, bp;

void findP(int a[], int N, multiset<int>& p)
{
	for (int i = 0; i < N; i++) {
		int t = a[i];
		for (int j = 2; j <= ceil(sqrt(a[i])) && (t != 1); j++) {
			while (!(t % j)) {
				p.insert(j);
				t /= j;
			}
		}
		if (t != 1) p.insert(t);
	}
}

int main()
{
	bool ch = false;
	multiset<int>::iterator iter;
	int N, M, a[MAXN], b[MAXN];
	long long answer = 1;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) scanf("%d", &b[i]);

	findP(a, N, ap);
	findP(b, M, bp);

	for (iter = ap.begin(); iter != ap.end(); ++iter) {
		int p = *iter;
		multiset<int>::iterator iter_b = bp.find(p);
		if (iter_b != bp.end()) {
			int bc = bp.count(p), ac = ap.count(p);
			int mc = min(bc, ac);
			for (int i = 0; i < mc; i++) {
				answer *= p;
				if(!ch && answer >= 1000000000) ch = true;
				answer %= 1000000000;
			}
		}
		if (iter != ap.end()) ++iter;
		while (iter != ap.end() && *iter == p) ++iter;
		--iter;
	}
	
	printf(ch?"%09d":"%d", (int)answer);
	return 0;
}