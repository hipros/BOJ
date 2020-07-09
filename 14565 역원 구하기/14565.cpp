#include<bits/stdc++.h>
#define ll long long
using namespace std;

tuple<ll, ll, ll> extended_euclidean(ll a, ll b)
{
	if(b == 0) return make_tuple(a, 1, 0);
	ll g, x, y;
	tie(g, x, y) = extended_euclidean(b, a%b);
	return make_tuple(g, y, x-(a/b)*y);
}
ll inverse(ll a, ll M) {
	ll g, x, y;
	tie(g, x, y) = extended_euclidean(a, M);
	if(g == 1) {
		if(x < 0) x += M;
		return x % M;
	}
	else return -1;
}

int main ()
{
	pair<int, bool> p;
	ll A, N;
	scanf("%lld %lld", &N, &A);
	printf("%lld %lld", N-A, inverse(A, N));
	return 0;
}