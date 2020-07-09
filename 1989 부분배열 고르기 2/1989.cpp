#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct RETN{
	long long val;
	pair<int, int> interval;
	RETN(long long val, pair<int, int> interval): val(val), interval(interval) {};
	RETN() {};
};
long long sum[MAXN], A[MAXN];

RETN DC(int l, int r)
{
	if (l == r) return RETN(A[l]*A[l], make_pair(l, r));
	int mid = (l + r) / 2, ll = mid, rr = mid + 1;
	long long minv = min(A[ll], A[rr]);
	RETN ret = RETN((A[mid] + A[mid+1])*min(A[mid], A[mid+1]), make_pair(mid, mid+1));

	while (true) {
		if (rr + 1 <= r && ll - 1 >= l) {
			if (A[rr + 1] >= A[ll - 1]) {
				rr++;
				minv = min(minv, A[rr]);
			}
			else {
				ll--;
				minv = min(minv, A[ll]);
			}
		}
		else if (rr + 1 <= r) {
			rr++;
			minv = min(minv, A[rr]);
		}
		else if (ll - 1 >= l) {
			ll--;
			minv = min(minv, A[ll]);
		}
		else break;

		if (ret.val < minv * (sum[rr] - sum[ll - 1])){
			ret.val = 	minv * (sum[rr] - sum[ll - 1]);
			ret.interval = make_pair(ll, rr);
		}
	}
	RETN left = DC(l, mid), right = DC(mid+1, r);
	if(ret.val < left.val) ret = left;
	if(ret.val < right.val) ret = right;
	return ret;
}

int main()
{
	RETN answer;
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]), sum[i] = sum[i - 1] + A[i];
	answer = DC(1, N);
	printf("%lld\n%d %d", answer.val, answer.interval.first, answer.interval.second);

	return 0;
}