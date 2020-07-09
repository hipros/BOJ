#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;

struct line{ string st[31]; };
set<string> s[MAXN];
vector<line> l;
int str[35], adj = 0, N, K;

void dfs(int n)
{
	if(n == adj) {
		bool ch = false;
		for(int i = 0; i < N && ch; i++) {
			int j;
			for(j = 0; j < adj && s[i][str[j]] == l[i].s[j]; j++);
			if(j == adj) {
				ch = true;
				break;
			}
		}
		if(!ch)	K--;
		if(K == 0) {
			for(int i= 0 ; i < adj; i++) cout<< s[str[i]] << " ";
			return 1;
		}
	}
	else {
		for(int i = 0; i < s[n].size(); i++){
			str[n] = s[n][i];
			if(dfs(n+1)) return 1;
		} 
	}	
	return 0;
}
int main ()
{
	bool ch = false;
	cin>> N >>K;
	l.resize(N);
	for(int i = 0; i < N; i++){
		bool st = false;
		adj = 0;
		while(true) {
			cin >> input;
			l[i].s[adj] = input;
			if(input == "cow.") break;

			if(st) s[adj++].insert(input);
			else if(input == no) st = true;
		}
	}
	dfs(0);
	return 0;
}