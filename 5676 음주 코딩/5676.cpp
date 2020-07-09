#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

int N, tree[2][MAXN], num[MAXN]; //tree[0] : 0 sum, tree[1] : - sum

void update(int w, int iden, int val)
{
	while (w <= N) {
		tree[iden][w] += val;
		w += (w & -w);
	}
}
int sum(int w, int iden)
{
	int ret = 0;
	while (w) {
		ret += tree[iden][w];
		w -= (w & -w);
	}
	return ret;
}
int main()
{
	char input;
	int K, a, b;
	while (scanf("%d %d", &N, &K) == 2) {
		memset(tree[0], 0, sizeof(int)*(N + 1));
		memset(tree[1], 0, sizeof(int)*(N + 1));
		for (int i = 1; i <= N; i++) {
			scanf("%d", &num[i]);
			if (num[i] < 0) update(i, 1, 1);
			else if (num[i] == 0) update(i, 0, 1);
		}
		while (K--) {
			scanf(" %c %d %d", &input, &a, &b);
			if (input == 'C') {
				if (num[a] < 0) {
					if (b == 0) {
						update(a, 0, 1);
						update(a, 1, -1);
					}
					else if (b > 0)	update(a, 1, -1);
				}
				else if (num[a] == 0) {
					if (b < 0) {
						update(a, 0, -1);
						update(a, 1, 1);
					}
					else if (b > 0)	update(a, 0, -1);
				}
				else if (num[a] > 0) {
					if (b < 0) update(a, 1, 1);
					else if (b == 0) update(a, 0, 1);
				}
				num[a] = b;
			}
			else if (input == 'P') {
				int sb1 = sum(b, 1), sa1 = sum(a - 1, 1);
				if (sum(b, 0) - sum(a - 1, 0) > 0)	printf("0");
				else if (!((sb1 - sa1) % 2)) printf("+");
				else printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}