#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20005;

struct tem { int s, e; };
bool operator<(tem a, tem b) { return a.e > b.e; }

tem ct[MAXN];
set<int> num;
priority_queue<tem> pq;

int main()
{
	int answer = 0;
	int N, X, Y, Z;
	int h = 0, c = 0, com = 0;

	scanf("%d %d %d %d", &N, &X, &Y, &Z);
	c = N;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &ct[i].s, &ct[i].e);
		num.insert(ct[i].s); num.insert(ct[i].e);
	}
	sort(ct, ct + N, [](const tem& a, const tem& b) {
		return a.s < b.s;
	});

	answer = c * X + com * Y + h * Z;
	for (int time : num) {
		while (com+h < N && time >= ct[com + h].s) {
			pq.push(ct[com + h]);
			com++;
			c--;
		}
		while (!pq.empty() && time > pq.top().e) {
			pq.pop();
			h++;
			com--;
		}

		int calc = c * X + com * Y + h * Z;
		answer = max(answer, calc);
	}
	printf("%d", answer);
	return 0;
}