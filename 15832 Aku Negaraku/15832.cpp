#include<bits/stdc++.h>
using namespace std;

int main ()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	while(1) {
		int N, M, answer = 1;
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		for(int i = 2; i <=N; i++) answer = ((answer+M-1)%i)+1;
		cout << answer << '\n';
	}
	return 0;
}