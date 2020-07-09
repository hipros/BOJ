#include<bits/stdc++.h>
#define MAXN 500001
using namespace std;

long long speed[MAXN], BIT[MAXN];
int order[MAXN], N;

int sum(int w){
	int ret = 0;
	while(w > 0){
		ret += BIT[w];
		w -= (w & -w);
	}
	return ret;
}
void update(int w){
	while(w <= N){
		BIT[w] += 1;
		w += (w & -w);
	}
}
int main ()
{
	int answer[MAXN];
	scanf("%d", &N);
	for(int i = 1;i <= N; i++) scanf("%lld", &speed[i]);
	for(int i = 1;i <= N; i++) order[i] = i;

	sort(order+1, order+N+1, [](const int &a, const int &b){
		return speed[a] > speed[b];
	});

	for(int i = 1;i <= N; i++) {
		int ord = order[i];
		update(ord);
		answer[ord] = sum(ord);
	}
	for(int i = 1;i <= N; i++) printf("%d\n", answer[i]);
	return 0;
}