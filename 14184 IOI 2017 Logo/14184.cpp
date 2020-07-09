#include<bits/stdc++.h>
using namespace std;
const int MAXN = (int)(1e6) + 5;

struct score{
	int sc;
	int fv;
	int sv;
	bool operator>(score d){
		return (sc > d.sc)
			|| (sc == d.sc && fv > d.fv)
			|| (sc == d.sc && fv == d.fv && sv > d.sv);
	}
	bool operator==(score d){
		return sc == d.sc
			&& fv == d.fv
			&& sv == d.sv;
	}
};

score tb[MAXN];
int N, ord[MAXN];
vector<int> srt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		memset(tb, 0, sizeof(tb));
		srt.clear();
		
		cin >> N;
		if (!N) break;

		for (int i = 0; i < N; i++) {
			int M;
			cin >> M;
			for (int j = 3; j > 3 - M; j--) {
				int v;
				cin >> v;
				tb[v].sc += j; tb[v].fv += (j == 3); tb[v].sv += (j == 2);
			}
		}

		for (int i = 1; i < MAXN; i++) ord[i] = i;
		sort(ord + 1, ord + MAXN, [](const int& a, const int& b){
			return tb[a] > tb[b];
		});
		srt.push_back(ord[1]);
		for (int i = 2; i < MAXN && tb[ord[i - 1]] == tb[ord[i]]; i++) srt.push_back(ord[i]);
		sort(srt.begin(), srt.end());

		for(int ans : srt) cout << ans <<' ';
		cout << '\n';
	}
	return 0;
}