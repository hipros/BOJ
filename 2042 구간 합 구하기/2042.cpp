#include<bits/stdc++.h>
#define MAXN ((1<<20)+5)
#define ll long long
using namespace std;
ll num[MAXN], tree[MAXN*2];

ll init(int w, int begin, int end)
{
	if(begin == end) return tree[w] = num[begin];
	int mid = (begin + end) /2;
	return tree[w] = init(w*2, begin, mid) + init(w*2+1, mid+1, end);
}
void update(int w, int begin, int end, int ch, ll diff)
{
	if(begin > ch || end < ch) return;
	tree[w] += diff;
	if(begin == end) return;
	int mid = (begin + end) /2;
	update(w*2, begin, mid, ch, diff);
	update(w*2+1, mid+1, end, ch, diff);
}
ll sum(int w, int begin, int end, int left, int right)
{
	if(end < left || begin > right) return 0;
	if(begin >= left && end <= right) return tree[w];
	int mid = (begin + end) /2;
	return sum(w*2, begin, mid, left, right) + sum(w*2+1, mid+1, end, left, right);
}

int main ()
{
	int N, M, K, a, b, k;
	ll c;
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 1; i<=N; i++) scanf("%lld", &num[i]);
	for(k = 1; k < N; k = (k<<1)); N = k;
	init(1, 1, N);
	for(int i = 0;i < M+K; i++) {
		scanf("%d", &a);
		if(a == 1){
			scanf("%d %lld", &b, &c);
			update(1, 1, N, b, c - num[b]);
			num[b] = c;
		}		
		else if(a == 2) {
			scanf("%d %lld", &b, &c);
			printf("%lld\n", sum(1, 1, N, b, c));
		}
	}
	return 0;
}