#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	char str[15];
	int val;
	stack<int> st;
	scanf("%d", &N);
	while (N--) {
		scanf(" %s", str);
		if (!strcmp(str, "push")) {
			scanf("%d", &val);
			st.push(val);
		}
		else if (!strcmp(str, "pop")) {
			if (!st.size()) printf("-1\n");
			else printf("%d\n", st.top()), st.pop();
		}
		else if (!strcmp(str, "size")) {
			printf("%d\n", st.size());
		}
		else if (!strcmp(str, "empty")) {
			printf("%d\n", (st.size()) ? 0 : 1);
		}
		else {
			printf("%d\n", (st.size()) ? st.top() : -1);
		}
	}
	return 0;
}