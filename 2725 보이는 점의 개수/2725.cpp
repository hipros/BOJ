#include<bits/stdc++.h>
#define MAXN 1000
using namespace std;

vector<int> prime, eulerphi;

void eratos(int n)
{
	bool isPrime[MAXN+1];
	memset(isPrime, true, sizeof(bool)*(MAXN+1));
	for(int i = 2; i*i <= n; i++){
		if(!isPrime[i]) continue;
		for(int j = i*i ; j <= n ; j+=i){
			isPrime[j] = false;
		}
	}
	for(int i = 2; i <=n; i++){
		if(isPrime[i]) prime.push_back(i);
	}
}

long long sigmaEulerPhi(int n)
{
	long long ret = 0, num;
	for(int i = eulerphi.size()+1;i <= n; ++i) {
		num = 1LL * i;
		for(int j = 0;j < prime.size() && prime[j] <= i; ++j) {
			if(i % prime[j] == 0) num = num * (prime[j]-1) / prime[j];
		}
		eulerphi.push_back(num);
	}
	for(int i = 0;i < n; i++) ret += eulerphi[i];

	return ret;
}
int main ()
{
	int T, n[MAXN];
	long long ans;
	scanf("%d", &T);
	
	eratos(MAXN);

	for(;T;--T) {
		scanf("%d", &n[T]);
		ans = 1 + 2*sigmaEulerPhi(n[T]);
		printf("%d\n", ans);
	}
	return 0;
}

