#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500;
unsigned long long dp[MAXN];

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	dp[0] = 0; dp[1] =1;
	for(int i = 2; i <= 490; i++) dp[i] = dp[i-1]+dp[i-2];

	while(1) {
		int N;
		cin >> N;
		if(N == -1) break;
		cout<<"Hour "<<N<<": " << dp[N] << " cow(s) affected\n";
	}
	return 0;
}