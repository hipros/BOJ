#include<cstdio>
#include<vector>
#define MAXN 201

using namespace std;

vector<vector<int> > conn;
int visit[MAXN], house[MAXN];

bool findmatch(int cow)
{
	int j;
	visit[cow] = 1;
	for (j = 0; j < conn[cow].size(); j++) {
		if (house[conn[cow][j]] == 0 || (visit[conn[cow][j]] == 0 && findmatch(house[conn[cow][j]]))) {
			break;
		}
		
	}
	visit[cow] = 0;
	if (j != conn[cow].size()) {
		house[conn[cow][j]] = cow;
		return true;
	}
	return false;
}

int main()
{
	int N, M, cn, c, count = 0;
	scanf("%d %d", &N, &M);
	conn.assign(N+1, vector<int>(0,0));

	for (int i = 1; i <= N; i++) {
		scanf("%d", &cn);
		for (int j = 0; j < cn; j++) {
			scanf("%d", &c);
			conn[i].push_back(c);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (findmatch(i)) 
			count++;
	}
	
	printf("%d", count);

	return 0;
}