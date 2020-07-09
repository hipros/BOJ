#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> input(N);
	vector<int> updy(N);
	vector<int> downdy(N, 0);

	for (int i = 0; i < N; i++) cin >> input.at(i);

	for (int i = 0; i < N; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (input[i] > input[j] && max < updy[j]) max = updy[j];
		}
		updy[i] = max+1;
	}

	for (int i = N-1; i >= 0; i--) {
		int max = 0;
		for (int j = i+1; j < N; j++) {
			if (input[i] > input[j] && max < downdy[j]) max = downdy[j];
		}
		downdy[i] = max + 1;
	}

	int output = 1;
	for (int i = 0; i < N; i++) {
		if (output < updy[i] + downdy[i]) output = updy[i] + downdy[i];
	}

	cout << output-1;
	
	system("pause");
	return 0;
}