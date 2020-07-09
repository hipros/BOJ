#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;

struct strbl{
	char s[52];
	int cnt = 0;
}str[MAXN];

bool comp(strbl a, strbl b)
{
	string astr = a.s, bstr = b.s;

	if(astr.size() == bstr.size()) {
		if(a.cnt == b.cnt)
			return (astr.compare(bstr) < 0);
		else
			return a.cnt < b.cnt;
	}
	else 
		return astr.size() < bstr.size();
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%s", str[i].s);
		for(int j = 0; j < strlen(str[i].s); j++) {
			if(str[i].s[j] >= '0' && str[i].s[j] <= '9') 
				str[i].cnt += (str[i].s[j] - '0');
		}
	}
	sort(str, str+N, comp);

	for(int i = 0; i < N; i++) printf("%s\n", str[i].s);
		
	return 0;
}