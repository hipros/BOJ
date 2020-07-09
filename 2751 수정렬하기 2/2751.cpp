#include<bits/stdc++.h>
using namespace std;
vector<int> n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	n.resize(N);
	for(int i = 0; i < N; i++) cin>> n[i];
	sort(n.begin(), n.end());
	for(int i = 0; i < N; i++) cout << n[i] <<'\n';
	return 0;
}