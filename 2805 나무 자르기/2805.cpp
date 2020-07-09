#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
	int N, input, sameLen = 0;
	ll M, answer, temp, sum = 0;
	vector<ll> log;
	scanf("%d %lld", &N, &M);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d", &input);
		log.push_back(input);
	}
	sort(log.begin(), log.end(), [](ll a, ll b) {
		return a>b;
	});
	log.push_back(0);
	for (int i = 1; i <= N; i += sameLen) {
		sameLen = 1;
		while (i+sameLen <= N && log[i] == log[i + sameLen]) ++sameLen;
		temp = sum;
		sum += (log[i - 1] - log[i]) * i;
		if (sum >= M) {
			answer = log[i];
			if (sum != M) answer += ((sum - M) / i);
			printf("%lld", answer);
			break;
		}
	}
	return 0;
}