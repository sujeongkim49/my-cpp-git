/*#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool solution(string s) {
	stack<char> stack;

	for (char c : s) {
		if (c == '(') {
			stack.push(c);
		}
		else if (c == ')') {
			if (stack.empty()) {
				return false;
			}
			else {
				stack.pop();
			}
		}
	}
	return stack.empty();
	//스택이 비어 있다면 괄호가 올바르게 닫힌 것 > true
	//스택에 남아있는 괄호가 있다면 올바르게 닫히지 않은 것 > false
}*/