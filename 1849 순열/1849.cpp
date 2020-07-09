#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int N, seq[MAXN], tree[MAXN], output[MAXN];

void update(int w, int val)
{
	while (w <= N) {
		tree[w]+= val;
		w += (w & -w);
	}
}
int sum(int w)
{
	int ret = 0;
	while (w) {
		ret += tree[w];
		w -= (w &-w);
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &seq[i]);
	for (int i = 1; i <= N; i++) {
		update(i, 1);
		seq[i]++;
	}
	for (int i = 1; i <= N; i++) {
		int l = 1, r = N;
		while (l <= r) {
			int mid = (l + r) / 2;
			int s = sum(mid);
			if (s == seq[i] && !output[mid]) {
				output[mid] = i;
				update(mid, -1);
				break;
			}
			else if (s < seq[i]) l = mid + 1;
			else if (s >= seq[i]) r = mid - 1;
		}
	}
	for (int i = 1; i <= N; i++) printf("%d\n", output[i]);
	return 0;
}