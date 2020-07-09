#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	vector<unsigned int> dy;
	vector<unsigned int> input;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		input.push_back(t);
	}

	dy.push_back(1);
	for (int i = 1; i < N; i++) {
		unsigned int max = 0;
		for (int j = 0; j < i; j++) {
			if (max < dy[j] && input[i] > input[j]) max = dy[j];
		}
		dy.push_back(max + 1);
	}
	int outmax = 0;
	for (int i = 0; i < N; i++) {
		if (outmax < dy[i]) outmax = dy[i];
	}

	cout << outmax;
	//system("pause");
	return 0;
}