#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	stack<int> st;
	scanf("%d ", &N);
	while (N--) {
		char c;
		bool isProper = true;
		while (scanf("%1c", &c) && c != '\n') {
			if (!isProper) continue;
			if (c == '(') st.push(0);
			else if (c == ')') {
				if (!st.size()) {
					printf("NO\n");
					isProper = false;
				}
				else st.pop();
			}
		}
		if (isProper && !st.size()) printf("YES\n");
		else if (isProper && st.size()) printf("NO\n");
		while (st.size()) st.pop();
	}
	return 0;
}