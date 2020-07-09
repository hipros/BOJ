#include<bits/stdc++.h>
using namespace std;
const int MN = (1e6)+5;
short stk[MN];
int order[MN];
vector<int> elist;
set<int> rest;

int main ()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);cout.tie(NULL);
	int T, N;
	cin >> T;

	while(T--) {
		long long answer = 0;
		cin >> N;
		for(int i = 0; i < N; i++) cin >> stk[i];
		for(int i = 0; i < N; i++) rest.insert(i);
		for(int i = 0; i < N; i++) order[i] = i;
		sort(order, order+N, [&](const int& a, const int& b) {
			return stk[a] > stk[b] || (stk[a] == stk[b] && a > b);
		});
		
		int i = 0;
		while(!rest.empty()) {
			for(int t : rest) {
				elist.push_back(t);
				if(t == order[i]) break;
				answer += (stk[order[i]] - stk[t]);
			}

			for(int t : elist) rest.erase(t);
			elist.clear();
			i++;
		}
		cout << answer << '\n';
	}	
	return 0;
}