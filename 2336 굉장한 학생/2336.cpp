#include<bits/stdc++.h>
using namespace std;

int main ()
{
	
	return 0;
}

/*#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
int stu[3][MAXN], value[MAXN], tree[MAXN], order[3][MAXN], seq[MAXN], N;

void update(int w)
{
	while (w <= N) {
		tree[w]++;
		w += (w & -w);
	}
}
int sum(int w)
{
	int ret = 0;
	while (w) {
		ret += tree[w];
		w -= (w & -w);
	}
	return ret;
}
int main()
{
	int answer = 0;
	scanf("%d", &N);
	for (int k = 0; k < 3; k++) for (int i = 1; i <= N; i++) scanf("%d", &stu[k][i]);
	for (int k = 0; k < 3; k++) for (int i = 1; i <= N; i++) order[k][i] = i;

	for (int i = 1; i < 3; i++) {
		sort(order[i] + 1, order[i] + N + 1, [i](const int &a, const int &b) {
			return stu[i][a] < stu[i][b];
		});
	}
	for (int i = 1; i <= N; i++) seq[i] = stu[0][i];
	for (int i = 1; i <= N; i++) value[seq[i]] = i - 1;
	for (int k = 1; k < 3; k++) {
		memset(tree + 1, 0, sizeof(int) * (N + 1));
		for (int i = 1; i <= N; i++) {
			int pre = sum(order[k][seq[i]]);
			value[seq[i]] = min(value[seq[i]], pre);
			update(order[k][seq[i]]);
		}
		sort(seq + 1, seq + N + 1, [k](const int &a, const int &b) {
			if (value[a] == value[b])
				return order[k + 1][a] > order[k + 1][b];
			return value[a] < value[b];
		});
	}
	for (int i = 1; i <= N; i++) {
		if (value[i] == 0) answer++;
	}
	printf("%d", answer);

	return 0;
}*/