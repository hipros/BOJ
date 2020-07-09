#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int main()
{
	int N, K, innum = 0, answer = 0, i, j;
	int seq[MAXN], next[MAXN], plugin[MAXN];
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= K; i++) scanf("%d", &seq[i]);
	fill(next + 1, next + K + 1, -1);
	fill(plugin + 1, plugin + K + 1, 0);
	for (i = 1; i < K; i++) {
		for (j = i + 1; j < K && seq[i] != seq[j]; j++);
		if (j != K) next[i] = j;
	}
	for (i = 1; i <= K; i++) {
		if (plugin[seq[i]]) {
			plugin[seq[i]] = next[i];
			continue;
		}
		if (innum < N) {
			plugin[seq[i]] = next[i];
			innum++;
		}
		else {
			int mostfar = 0;
			for (j = 1; j <= K; j++) {
				if (plugin[j] != 0) {
					if (plugin[j] == -1) {
						mostfar = j;
						break;
					}
					if (plugin[j] > plugin[mostfar]) mostfar = j;
				}
			}
			plugin[mostfar] = 0;
			plugin[seq[i]] = next[i];
			answer++;
		}
	}
	printf("%d", answer);
	return 0;
}