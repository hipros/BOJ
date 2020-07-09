#include<bits/stdc++.h>
#define MAXN 1000000
using namespace std;

struct line{
	long long s,e;
	long long sub() {
		return e-s;
	}
	void swap(){
		long long t = s;
		s = e;
		e = t;
	}
};
line l[MAXN];

int main ()
{
	long long ans = 0;
	line calc;
	int N;
	scanf("%d", &N);
	for(int i = 0;i < N; i++){
		scanf("%lld %lld", &l[i].s, &l[i].e);
		if(l[i].s > l[i].e) l[i].swap();
	}
	sort(l, l+N, [](line a, line b){
		if(a.s == b.s)
			return a.e < b.e;
		else
			return a.s < b.s;
	});
	calc.s = l[0].s; calc.e = l[0].e;
	ans = calc.sub();
	for(int i = 1;i <N; i++){
		if(l[i].s > calc.e){
			calc.s = l[i].s; calc.e = l[i].e;
			ans += calc.sub();
		}
		else if(l[i].e > calc.e){
			ans += (l[i].e-calc.e);
			calc.e = l[i].e;
		}
	}
	printf("%lld", ans);
	return 0;	
}