#include<bits/stdc++.h>
using namespace std;
const int MAXN = (int)25;
struct edge{ int s, e, d; };
bool operator<(edge a, edge b){ return a.d > b.d; }
priority_queue<edge> pq;
int gp[MAXN];

int find(int a)
{
	if(gp[a] == a) return a;
	else return gp[a] = find(gp[a]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for(int t = 1; t <=T; t++) {
		int N, M, answer = 0, cnt;
		cin>> N >> M;

		for(int i = 1; i <= N; i++) gp[i] = i;
		cnt = N;

		for(int i = 0; i < M; i++) {
			edge input;
			cin >> input.s >> input.e >> input.d;
			pq.push(input);
		}

		while(!pq.empty() && cnt > 1) {
			edge now = pq.top(); pq.pop();
			int ga = find(now.s), gb = find(now.e);
			if(ga != gb) {
				answer += now.d;
				gp[ga] = gp[gb];
				cnt--;
			}
		}
		
		while(!pq.empty()) pq.pop();
		cout << "Case #"<< t <<": "<< answer <<" meters\n";
	}
	return 0;
}