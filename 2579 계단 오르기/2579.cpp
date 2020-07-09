#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<unsigned int> d(N);
	vector<int> s(N);
	for (int i = 0; i < N; i++)
		cin >> s.at(i);

	d.at(0) = s.at(0);
	for (int i = 1; i < N && i < 2; i++) {
		d.at(i) = s.at(i) + d.at(i - 1);
	}

	for (int i = 2; i < N; i++) {
		int t = 0;
		if (i > 2) t = d[i - 3];
		if (d[i - 2] > s[i - 1] + t) d[i] = d[i - 2] + s[i];
		else d[i] = s[i - 1] + t + s[i];
	}

	cout << d[N - 1];
	system("pause");
	return 0;
}