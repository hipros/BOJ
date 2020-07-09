#include<bits/stdc++.h>
#define MAXN 100001
using namespace std;
int dp[MAXN][5][5], input[MAXN], N;

int mvw(int from, int to)
{
	if (from == to) return 1;
	if (from == 0 || to == 0) return 2;
	if (abs(from - to) == 2) return 4;
	return 3;
}

int DP(int l, int r, int seq)
{
	int t1, t2;
	if (seq == N) return 0;
	int &ret = dp[seq][l][r];
	if(ret) return ret;

	if (input[seq] == l || input[seq] == r) ret = DP(l, r, seq + 1) + 1;
	else {
		t1 = DP(input[seq], r, seq + 1) + mvw(l, input[seq]);
		t2 = DP(l, input[seq], seq + 1) + mvw(r, input[seq]);
		ret = min(t1, t2);
	}
	return ret;
}
int main()
{
	int answer;
	for (N = 0; N == 0 || input[N - 1] != 0; N++) scanf("%d", &input[N]);
	N--;
	answer = DP(0, 0, 0);
	printf("%d", answer);
	return 0;
}