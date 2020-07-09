#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int E, S, M, year = 1;
	int esm[3]={1, 1, 1};
	scanf("%d %d %d", &E, &S, &M);
	while(!(esm[0] == E && esm[1] == S && esm[2] == M)){
		year++;
		for(int i = 0;i < 3; i++) esm[i]++;
		if(esm[0]==16) esm[0]= 1;
		if(esm[1]==29) esm[1]= 1;
		if(esm[2]==20) esm[2]= 1;
	}
	printf("%d", year);
	return 0;
}