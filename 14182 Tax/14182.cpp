#include<bits/stdc++.h>
using namespace std;

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while(1){
		int N;
		cin>> N;
		if(N == 0) break;
		N -= ((N > (int)1e6 && N <= (int)5e6)* N/10 + (N > (int)5e6) * N/5);
		cout << N <<'\n';
	}
	return 0;
}