#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, max = 0;
	cin >> N;

	vector<int> input(N);
	for (int i = 0; i < N; i++) {
		cin >> input.at(i);
	}
	int dy = input.at(0);
	max = dy;
	for (int i = 1; i < N; i++) {
		if (max < dy) max = dy;
		if (input[i-1] < 0) {
			if (input[i] > dy + input[i]) {
				dy = input[i];
				continue;
			}
		}
		dy += input[i];
	}
	max = (dy < max) ? max : dy;
	cout << max;
	system("pause");
	return 0;
}