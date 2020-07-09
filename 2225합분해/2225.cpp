#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, K;
	vector<vector<long long int> > dy;
	cin >> N >> K;

	dy.assign(K, vector<long long int>(N+1, 0));

	for (int i = 0; i < N + 1; i++)
		dy[0][i] = 1;

	for (int i = 1; i < K; i++) {
		for (int j = 0; j < N+1; j++) {
			for (int k = 0; k <= j; k++) {
				dy[i][j] += (dy[i - 1][k] % 1000000000);
			}
			dy[i][j] %= 1000000000;
		}
	}

	cout << dy[K-1][N];

	system("pause");
	return 0;
}