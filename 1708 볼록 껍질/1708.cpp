#include<cstdio>
#include<algorithm>
#include<iostream>
#include<stack>

using namespace std;
#define MAXN 100000

pair<int, int> po = {0,40000};

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	long long t = 1LL * a.first*b.second + 1LL *b.first*c.second + 1LL *c.first*a.second;
	t -= 1LL *a.second*b.first + 1LL *b.second*c.first + 1LL *c.second*a.first;
	if(t == 0) return 0;
	return (t > 0) ? -1:1;
}
long long dist(pair<int, int> a, pair<int, int> b)
{
	return 1LL * (a.first-b.first)*(a.first-b.first) + 1LL * (a.second-b.second)*(a.second-b.second);
}
bool compare(pair<int, int> a, pair<int, int> b)
{
	int t = ccw(po, a, b);
	if(t == 0) return (dist(po, a) < dist(po, b)) ?  true : false;
	return (t < 0) ? true : false;
}
pair<int, int> secondTop(stack<pair<int, int>> S)
{
	pair<int, int> t = S.top(), ret;
	S.pop();
	ret = S.top(); S.push(t);
	return ret;
}
int swap(pair<int, int> *a, pair<int, int> *b)
{
	pair<int, int> t = *a;
	a = b;
	*b = t;
}
int main ()
{
	int n, answer, mini = 0;
	stack<pair<int, int>> S;
	pair<int, int> p[MAXN+1];
	scanf("%d", &n);
	for(int i = 0;i < n; i++){
		scanf("%d %d", &p[i].first, &p[i].second);
		if ((p[i].second < po.second) || (po.second == p[i].second && p[i].first < p[mini].first)) {
			po.first = p[i].first; po.second = p[i].second;
			mini = i;
		}
	}
	swap(p[0], p[mini]);
	sort(p+1, p+n, compare);

	S.push(p[0]); S.push(p[1]);

	for(int i = 2; i < n; i++) {
		while(S.size() >= 2 && ccw(secondTop(S), S.top(), p[i]) >= 0) {
			S.pop();
		}
		S.push(p[i]);
	}
	answer = S.size();
	printf("%d\n", answer);

	return 0;
}