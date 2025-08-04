/*#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, char> bracketPair = { {')', '('}, {']', '['}, {'}', '{'} };
//맵 선언

bool isValid(string& s, int start) {
	stack<char> stk;
	//stk는 비어있는 상태
	unsigned int sz = s.size();

	for (int i = 0; i < sz; i++) {
		char ch = s[(start + i) % sz];
		//(start + i) % sz > 문자열 회전 구현

		if (bracketPair.count(ch)) {
			//해당 키가 있으면 1 반환, 없으면 0반환 > ch=) > count()) = 1 > true
			//ch=( > count(() = 0 > false

			if (stk.empty() || stk.top() != bracketPair[ch]) {
				return false;
				//첫 문자열이 닫는 괄호로 시작하면 바로 false 반환
				//스택의 맨 위에 있는 괄호가 짝이 맞지 않으면 false 반환
			}
			stk.pop();
			//올바른 짝이기 때문에 스택에서 제거
		}
		else {
			stk.push(ch);
			//여는 괄호이므로 스택에 넣어서 나중에 짝 검사에 사용
		}
	}
	return stk.empty();
}

int solution(string s) {
	int answer = 0;
	int n = s.size();

	for (int i = 0; i < n; i++) {
		answer += isValid(s, i);
		//isValid 함수가 true면 1, false면 0이 더해짐.
	}
	return answer;
}*/