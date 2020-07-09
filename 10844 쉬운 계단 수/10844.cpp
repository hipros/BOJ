#include<iostream>

using namespace std;

int main()
{
	int N;
	unsigned int sum = 0;
	unsigned int p[2][10] = { 0, };

	cin >> N;
	for (int i = 1; i < 10; i++) p[1][i] = 1;

	for (int i = 0; i < N-1; i++) {
		int t = i%2;
		
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) p[t][j] = p[(t + 1) % 2][j-1];
			if (j + 1 < 10) p[t][j] = (p[t][j] + p[(t + 1) % 2][j+1]) % 1000000000;
		}

		for (int j = 0; j < 10; j++) p[(t + 1) % 2][j] = 0;
	}

	for (int i = 0; i < 10; i++)
		sum = (sum + p[N%2][i]) % 1000000000;

	cout << sum;

	system("pause");
	return 0;
}