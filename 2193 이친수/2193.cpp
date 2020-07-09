#include <iostream>
#include<vector>

using namespace std;

int main()
{
	vector<pair<unsigned long, unsigned long> > dy;
	int N;

	cin >> N;
	pair<unsigned long, unsigned long> p;
	p.first = 0;
	p.second = 1;
	dy.push_back(p);

	for (int i = 1; i < N; i++) {
		p.first = dy[i - 1].first + dy[i - 1].second;
		p.second = dy[i - 1].first;
		dy.push_back(p);
	}

	cout << dy[N - 1].first + dy[N - 1].second;

	system("pause");
	return 0;
}