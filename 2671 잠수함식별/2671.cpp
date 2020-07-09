#include<bits/stdc++.h>
using namespace std;

string str;
short stateT[2][10] = {{1,8,4,1,5,5,7,5,8,1}, {2,3,8,2,8,9,6,3,8,6}};

short detect()
{
	short st = 0;
	for(int i = 0; i < str.size() && st != 8; i++) st = stateT[str[i]-'0'][st];
	return st;
}

int main()
{
	short Answer;
	cin >> str;

	Answer = detect();
	if(Answer == 3 || Answer == 6 || Answer	== 9) printf("SUBMARINE");
	else printf("NOISE");

	return 0;
}