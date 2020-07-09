#include<bits/stdc++.h>
#define MAXN 100005

int wannabe[MAXN], seq[MAXN];
bool isTeam[MAXN];

int main()
{
	int T, N, cnt = 0, alone;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		alone = N; cnt = 0;
		memset(seq+1, 0, sizeof(int) * (N+1));
		memset(isTeam+1, 0, sizeof(int) * (N+1));
		for (int i = 1; i <= N; i++) scanf("%d", &wannabe[i]), isTeam[i] = false;

		for (int i = 1; i <= N; i++) {
			if (!isTeam[i]) {
				int t = i;
				++cnt;
				seq[i] = cnt;
				while (!isTeam[t]) {
					if (seq[wannabe[t]] == cnt) {
						int tt = wannabe[t];
						while (!isTeam[tt]) isTeam[tt] = true, tt = wannabe[tt], alone--;
					}
					else {
						if (seq[wannabe[t]]) break;
						seq[t] = cnt;
						t = wannabe[t];
					}
				}
			}
		}
		printf("%d\n", alone);
	}

	return 0;
}