#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector< vector<int> > dy(N , vector<int>(10,0));

	for (int i = 0; i < 10; i++) dy[0][i] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dy[i][j] += dy[i - 1][k];
				dy[i][j] %= 10007;
			}
		}
	}
	 
	unsigned int sum = 0;

	for (int i = 0; i < 10; i++) {
		sum += dy[N - 1][i];
		sum %= 10007;
	}

	cout << sum;
	system("pause");

	return 0;
}