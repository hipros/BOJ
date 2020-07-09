#include<cstdio>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int N;
	vector<int> d;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int input;
		scanf("%*d%d", &input);
		d.push_back(input);
	}
	
	for (int i = 0; i < N-1; i++) {
		if (d[i] == d[i + 1]) {
			printf("%d ", N-i);
		}
		else printf("%d ", 1);
	}
	putchar('1');
	//system("pause");
	return 0;
}