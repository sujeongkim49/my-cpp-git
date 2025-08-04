/*#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, char> bracketPair = { {')', '('}, {']', '['}, {'}', '{'} };
//�� ����

bool isValid(string& s, int start) {
	stack<char> stk;
	//stk�� ����ִ� ����
	unsigned int sz = s.size();

	for (int i = 0; i < sz; i++) {
		char ch = s[(start + i) % sz];
		//(start + i) % sz > ���ڿ� ȸ�� ����

		if (bracketPair.count(ch)) {
			//�ش� Ű�� ������ 1 ��ȯ, ������ 0��ȯ > ch=) > count()) = 1 > true
			//ch=( > count(() = 0 > false

			if (stk.empty() || stk.top() != bracketPair[ch]) {
				return false;
				//ù ���ڿ��� �ݴ� ��ȣ�� �����ϸ� �ٷ� false ��ȯ
				//������ �� ���� �ִ� ��ȣ�� ¦�� ���� ������ false ��ȯ
			}
			stk.pop();
			//�ùٸ� ¦�̱� ������ ���ÿ��� ����
		}
		else {
			stk.push(ch);
			//���� ��ȣ�̹Ƿ� ���ÿ� �־ ���߿� ¦ �˻翡 ���
		}
	}
	return stk.empty();
}

int solution(string s) {
	int answer = 0;
	int n = s.size();

	for (int i = 0; i < n; i++) {
		answer += isValid(s, i);
		//isValid �Լ��� true�� 1, false�� 0�� ������.
	}
	return answer;
}*/