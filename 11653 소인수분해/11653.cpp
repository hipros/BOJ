#include<bits/stdc++.h>
using namespace std;
int pnum = 2, N;

struct primedata{
	int p,cnt;
	primedata(int p, int cnt): p(p), cnt(cnt) {};
};
vector<primedata> p;

void DC(int n)
{
	int cnt = 0;
	if(n == 1) return;
	for(int i = pnum; i<=N ;i++){
		if(n % i == 0){
			while(n%i == 0) n /= i, cnt++;
			p.push_back(primedata(i, cnt));
			DC(n);
			break;
		}
	}
}

int main ()
{
	scanf("%d", &N);
	DC(N);
	for(primedata t: p){
		for(int i = 0; i < t.cnt; i++) printf("%d\n", t.p);
	}
	return 0;
}