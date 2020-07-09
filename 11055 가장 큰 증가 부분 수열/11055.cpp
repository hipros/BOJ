#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	vector<unsigned long> dyW;
	vector<unsigned int> input;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		input.push_back(t);
	}

	dyW.push_back(input.at(0));
	for (int i = 1; i < N; i++) {
		unsigned int w = -1;
		for (int j = 0; j < i; j++) {
			if ((w == -1 || dyW[w] < dyW[j]) && input[i] > input[j]) w = j;
		}
		
		dyW.push_back(input.at(i));
		if (w != -1) dyW[i] += dyW[w];
	}

	unsigned long outmax = dyW.at(0);
	for (int i = 0; i < N; i++) {
		if (outmax < dyW[i]) outmax = dyW[i];
	}

	cout << outmax;
	system("pause");
	return 0;
}