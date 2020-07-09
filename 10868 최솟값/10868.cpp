#include<bits/stdc++.h>
using namespace std;
const int MAXN = 262144, INF = 2e9;

int N, M, num[MAXN];
int seg(int a, int b, int l, int r, int w)
{
	if (a == l && b == r) return num[w];
	int m = (l + r) / 2;
	if (b <= m) return seg(a, b, l, m, w * 2);
	else if (a > m) return seg(a, b, m+1, r, w * 2 + 1);
	else return min(seg(a, m, l, m, w * 2), seg(m+1, b, m+1, r, w * 2 + 1));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int pad, cnt = 0, ndep;
	cin >> N >> M; 

	for (pad = 1; pad < N; pad <<= 1) cnt++;
	for (int i = 0; i < N; i++) cin >> num[pad + i];
	for (int i = pad + N; i < pad * 2; i++) num[i] = INF;
	ndep = pad;
	for (int depth = cnt; depth > 0; depth--){
		ndep /= 2;
		for (int w = ndep; w < ndep * 2; w++){
			num[w] = min(num[w * 2], num[w * 2 + 1]);
		}
	}
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		cout << seg(a, b, 1, pad , 1) << '\n';
	}
	return 0;
}