#include<bits/stdc++.h>
#define MAXN 105
using namespace std;

int w[MAXN];

int main()
{
	int N, answer = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &w[i]);
	sort(w+1, w + N+1);

	for(int i = 1; i < N; i++) w[i] = abs(w[i] - w[i+1]);
	w[0] = w[N] = 1005;

	for(int i = 1; i < N; i++) {
		if(w[i] < w[i-1] && w[i] <= w[i+1]) {
			answer++;
			if(i != 1 && i != N-1) answer += ((w[i-1] < w[i-2]) && (w[i+1] < w[i+2]));
		}
	}

	printf("%d", answer);
	return 0;
}