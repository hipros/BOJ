#include<bits/stdc++.h>
#define MAXN 100005
#define MAXC 1000000
using namespace std;
long long tree[MAXC + 5];
int candy[MAXC + 5];

void update(int w, int val)
{
	while (w <= MAXC) {
		tree[w] += val;
		w += (w & -w);
	}
}
long long sum(int w)
{
	long long ret = 0;
	while (w) {
		ret += tree[w];
		w -= (w & -w);
	}
	return ret;
}
int main()
{
	int N, a, b, c;
	scanf("%d", &N);
	for (int i = 0; i <N; i++) {
		scanf("%d %d", &a, &b);
		if (a == 1) {
			int low = 1, high = MAXC;
			while (low <= high) {
				int mid = (low + high) / 2;
				long long sm = sum(mid);
				if ((sm == b || (sm > b && sm-b < candy[mid])) && candy[mid]) {
					printf("%d\n", mid);
					update(mid, -1);
					candy[mid]--;
					break;
				}
				else if (sm >= b) high = mid - 1;
				else if (sm < b) low = mid + 1;
			}
		}
		else if (a == 2) {
			scanf("%d", &c);
			update(b, c);
			candy[b] += c;
		}
	}

	return 0;
}