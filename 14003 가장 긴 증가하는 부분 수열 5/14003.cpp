#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int seq[MAXN], lseq[MAXN], w[MAXN], llen = 1;
vector<int> answer;
int lowerBound(int num, int s, int e)
{
	int m;
	while(e - s > 0) {
		m = (s + e) / 2;
		if (num > lseq[m]) s = m + 1;
		else e = m;
	}
	return e;
}
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", seq + i);
	for (int i = 1; i <= N; i++)
	{
		int lb = lowerBound(seq[i], 1, llen);
		lseq[lb] = seq[i];
		w[i] = lb;
		if(lb == llen) llen++;
	}
	int f = llen-1;
	printf("%d\n", llen-1);
	for (int i = N; i >= 1; i--) {
		if (w[i] == f) {
			answer.push_back(seq[i]);
			f--;
		}
	}
	for(int i = answer.size()-1; i >= 0; i--) printf("%d ", answer[i]);
	return 0;
}