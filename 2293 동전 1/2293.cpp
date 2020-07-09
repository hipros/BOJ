#include<bits/stdc++.h>
using namespace std;
const int MAXK = 10005;
vector<int> C;
int dp[MAXK];

int main ()
{
	int N, K, t;
	cin >> N >>K;
	for(int i = 1; i <= N; i++){
		cin>>t;
		if(t <= K) C.push_back(t);
	}

	dp[0] = 1;
	for(int c : C){
		for(int j  = c; j <= K; j++){
			dp[j] += dp[j-c];
		}
	}
	
	cout<<dp[K];
	return 0;
}