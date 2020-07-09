#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		int N;
		cin >> N;
		vector<vector<unsigned long> > table(2, vector<unsigned long>(N, 0));
		vector<vector<unsigned long> > dy(2, vector<unsigned long>(N, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> table[i][j];
			}
		}

		dy[0][0] = table[0][0];
		dy[1][0] = table[1][0];

		for (int i = 1; i < N; i++) {
			for (int j = 0; j < 2; j++) {
				unsigned long max = 0;

				if (i - 2 >= 0)	max = dy[(j + 1) % 2][i-2];

				if (max < dy[(j + 1) % 2][i - 1]) max = dy[(j + 1) % 2][i - 1];

				dy[j][i] = max + table[j][i];
			}
		}
		unsigned long output = (dy[0][N - 1] > dy[1][N - 1]) ? dy[0][N - 1] : dy[1][N - 1];

		cout << output << endl;
	}

	system("pause");
	return 0;
}