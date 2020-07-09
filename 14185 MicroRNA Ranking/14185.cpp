#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1001;

int seq[MAXN][MAXN];
int indeg[MAXN];
vector<int> outdeg[MAXN];
bool vis[MAXN];

int main()
{
	while (1){
		vector<int> ans;
		int N, K;
		cin >> N >> K;
		if (!N && !K) break;
		for (int i = 0; i <= N; i++){
			vis[i] = false; indeg[i] = 0; outdeg[i].clear();
			memset(seq[i], 0, sizeof(seq[0][0])*(N + 1));
		}

		for (int i = 0; i < K; i++){
			int tseq[MAXN];
			for (int j = 0; j < N; j++) {
				cin >> tseq[j];
				for (int k = 0; k < j; k++) seq[tseq[j]][tseq[k]]++;
			}
		}
		for (int s = 1; s <= N; s++) for (int d = 1; d <= N; d++){
			if (seq[s][d] >= (K / 2.0)) {
				indeg[d]++;
				outdeg[s].push_back(d);
			}
		}

		bool isp = true;
		for (int i = N - 1; i >= 0 && isp; i--){
			isp = false;
			for (int j = 1; j <= N; j++){
				if (!vis[j] && indeg[j] == i) {
					ans.push_back(j);
					vis[j] = isp = true;
					for (int to : outdeg[j]) indeg[to]--;
				}
			}
		}

		if (ans.size() == N) for (int a : ans) cout << a << " ";
		else cout << "No solution";
		cout << '\n';
	}
	return 0;
}