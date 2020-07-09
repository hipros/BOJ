#include<cstdio>
#include<vector>
using namespace std;

vector<pair<int, int>> output;

void hanoi(int n, int s, int e)
{
	if(n == 1){
		output.push_back(make_pair(s, e));
	}
	else {
		hanoi(n-1, s, 6-s-e);
		hanoi(1, s, e);
		hanoi(n-1, 6-s-e, e);
	}
}

int main ()
{
	int n;
	scanf("%d", &n);

	hanoi(n, 1, 3);

	printf("%d\n", output.size());
	for(int i = 0;i < output.size(); i++) printf("%d %d\n", output[i].first, output[i].second);
	return 0;
}