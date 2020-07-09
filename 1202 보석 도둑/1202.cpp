#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
struct je{ int w, v; };

stack<int> s;
int volume[MAXN], K;
int nxt[MAXN];
je j[MAXN];

int find(int x)
{
	for(;nxt[x] != x; x = nxt[x]) s.push(x);
	for(;!s.empty();s.pop()) nxt[s.top()] = x;
	return x;
}
void Union(int p, int q)
{
	int pp = find(p);
	int pq = find(q);
	nxt[pp] = nxt[pq];
}
int main ()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int N, i;
	unsigned long long answer = 0;
	cin>>N>>K;
	for(i = 1; i<=N; i++) cin>>j[i].w>>j[i].v;
	for(i = 1; i <= K; i++) cin>>volume[i], nxt[i] = i;
	sort(j+1, j+N+1, [](const je& a, const je& b){
		return a.v > b.v || (a.v==b.v && a.w < b.w);
	});
	sort(volume+1, volume+K+1);

	nxt[K+1] = K+1;
	for(i = 1; i <= N; i++){
		int l = 1, r = K;
		while(l < r) {
			int mid = (l+r)/2;
			if(volume[mid] < j[i].w) l = mid+1;
			else r = mid;
		}
		if(volume[r] < j[i].w) continue;
		int o = find(r);
		if(o != K+1) {
			Union(o, o+1);
			answer += j[i].v;
		}
	}
	cout<<answer;
	return 0;
}