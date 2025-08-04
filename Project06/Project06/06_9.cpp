/*#include <iostream>
#include <stack>
#include <string>

using namespace std;

string solution(int decimal) {
	stack<int> stack;

	while (decimal > 0) {
		stack.push(decimal % 2);
		decimal /= 2;
	}
	string binary = "";
	while (!stack.empty()) {
		binary += to_string(stack.top());
		//to_string() 정수를 문자열로 반환하는 표준 라이브러리 함수
		stack.pop();
	}

	return binary;
}*/