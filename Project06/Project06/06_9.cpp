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
		//to_string() ������ ���ڿ��� ��ȯ�ϴ� ǥ�� ���̺귯�� �Լ�
		stack.pop();
	}

	return binary;
}*/