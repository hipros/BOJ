#include<bits/stdc++.h>
#define MAXV 10000
#define INF 2147483647
using namespace std;

int V, E, discover[MAXV+1], dcnum = 1, sccnum;
int scccheck[MAXV+1];
priority_queue<int, vector<int>, greater<int> > scc[MAXV];
vector<int> conn[MAXV+1];
stack<int> searchseq;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first < b.first) return true;
	return false;
}

int dfssearch(int node)
{
	int ret = INF;
	searchseq.push(node);
	discover[node] = dcnum;
	ret = dcnum++;
	for(int n : conn[node]){
		if(discover[n] == 0)
			ret = min(ret, dfssearch(n));
		else if(scccheck[n] == 0)
			ret = min(ret, discover[n]);
	}
	if(ret == discover[node]){
		int t;
		do{
			t = searchseq.top();searchseq.pop();
			scc[sccnum].push(t);
			scccheck[t] = sccnum+1;
		}while(t != node);
		sccnum++;
	}
	return ret;
}

int main ()
{
	int s, e;
	vector<pair<int, int> > qindex;
	scanf("%d %d", &V, &E);
	for(int i = 0;i < E; i++){
		scanf("%d %d", &s, &e);
		conn[s].push_back(e);
	}
	
	for(int i = 1;i <= V; i++){
		if(discover[i] == 0) {
			dfssearch(i);
		}
	}

	for(int i = 0;i < sccnum; i++)
		qindex.push_back(make_pair(scc[i].top(), i));

	sort(qindex.begin(), qindex.end(), cmp);

	printf("%d\n", sccnum);
	for(int i = 0;i < sccnum; i++) {
		int t = qindex[i].second, sz = scc[t].size();
		for(int j = 0;j < sz; j++){
			printf("%d ", scc[t].top());
			scc[t].pop();
		}
		printf("-1\n");
	}
	return 0;
}