#include<cstdio>
#include<queue>
#define MAXN 100

using namespace std;

struct cmp {
	bool operator()(long long a, long long b) {
		return a > b;
	}
};

priority_queue<long long, vector<long long>, cmp> q;
int K, N;
int num[MAXN+1];

int main()
{
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++)
		scanf("%d", &num[i]);

	for (int i = 0; i < K; i++)
		q.push(num[i]);

	while ((--N) != 0) {
		long long item = q.top(); q.pop();
		for (int i = 0; i < K; i++) {
			long long tmp = num[i] * item;
			q.push(tmp);
			if (item % num[i] == 0) break;
		}
	}
	printf("%lld", q.top());
	system("pause");
	return 0;
}