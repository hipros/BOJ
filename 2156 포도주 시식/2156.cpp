#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> w(N);
	vector<unsigned long> dy(N);

	for (int i = 0; i < N; i++) cin >> w[i];
	if (N == 1) {
		cout << w[0];
		return 0;
	}

	dy[0] = w[0]; dy[1] = dy[0] + w[1];

	for (int i = 2; i < N; i++) {
		if(i == 2) dy[i] = (w[0] > w[1]) ? w[0]: w[1];
		else dy[i] = (dy[i-2] > dy[i-3]+ w[i-1]) ? dy[i - 2] : dy[i - 3] + w[i - 1];
		dy[i] += w[i];
		if (dy[i] < dy[i - 1]) dy[i] = dy[i - 1];
	}
	unsigned long output = dy[N - 1];
	if (output < dy[N - 2]) output = dy[N - 2];
	cout << output << endl;

	system("pause");
	return 0;
}