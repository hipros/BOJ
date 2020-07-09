#include<cstdio>
#include<iostream>

using namespace std;

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	int t = a.first*b.second + b.first*c.second + c.first*a.second;
	t -= a.second*b.first + b.second*c.first + c.second*a.first;
	if(t == 0) return 0;
	return (t < 0) ? -1:1;
}

int main ()
{
	pair<int,int> point[3];
	int answer;
	for(int i = 0;i < 3; i++){
		scanf("%d %d", &point[i].first, &point[i].second);
	}
	answer = ccw(point[0], point[1], point[2]);
	printf("%d", answer);
	return 0;
}