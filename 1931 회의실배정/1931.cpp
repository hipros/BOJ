#include<bits/stdc++.h>
using namespace std;

struct Time {
	int s, e;
};
vector<Time> t;

int main ()
{
	int N, endtime = 0, answer = 0;
	scanf("%d", &N);
	t.resize(N);
	for(int i = 0; i < N; i++) scanf("%d %d", &t[i].s, &t[i].e);
	sort(t.begin(),t.end(), [](Time a, Time b){
		return (a.e < b.e) || (a.e == b.e && a.s < b.s);
	});

	for(Time tt : t) {
		if(endtime <= tt.s){
			answer ++;
			endtime = tt.e;
		}
	}
	printf("%d", answer);
	return 0;
}