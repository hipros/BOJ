#include<bits/stdc++.h>
#define MAXL 1005
using namespace std;

int s[MAXL], sl;

int main ()
{
	char input;
	while(scanf("%c", &input) == 1){
		if(input >= 'a' && input <= 'z') s[sl++] = 1;
		else if(input == '(') s[sl++] = 2;
		else if(input == ')') s[sl++] = 3;
		else if(input != ' ') sl[s]
	}
	return 0;
}