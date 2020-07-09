#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c) { return c == '+' || c == '-' || c == '%' || c == '/' || c == '*'; }
bool isChar(char c) { return c >= 'a' && c <= 'z'; }
stack<char> s;

int main()
{
	int parnum = 0, opernum = 0, close = 0;
	char c;
	while (scanf(" %c ", &c) == 1) {
		if (isChar(c)) {
			if (s.size() == 0 || isOperator(s.top()) || s.top() == '(') {
				s.push(c);
			}
			else {
				printf("error");
				return 0;
			}
		}
		else if (c == '(') {
			parnum++;
			if (s.size() == 0 || isOperator(s.top()) || s.top() == '(') {
				s.push(c);
			}
			else {
				printf("error");
				return 0;
			}
		}
		else if (c == ')') {
			close++;
			if (s.size() != 0 && isChar(s.top())) {
				int count = 0;
				for (; s.size() != 0 && s.top() != '('; s.pop(), count++);
				if (count == 3 && s.size()!=0) {
					s.pop();
					s.push('a');
				}
				else if (s.size() == 0 || count == 0) {
					printf("error");
					return 0;
				}
				else {
					printf("improper");
					return 0;
				}
			}
			else {
				printf("error");
				return 0;
			}
		}
		else if (s.size() != 0) { // +, -, *, %, /
			opernum++;
			if (isChar(s.top())) {
				s.push(c);
			}
			else {
				printf("error");
				return 0;
			}
		}
		else {
			printf("error");
			return 0;
		}
	}
	if (parnum != close) printf("error");
	else if (parnum == opernum - 1 || (!parnum && !opernum)) printf("proper");
	else printf("improper");
	return 0;
}