#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
using namespace std;

int prec(char op) {
	//prec = �켱����
	if (op == '+' || op == '-') return 1; //+, -�� �켱���� 1
	if (op == '*' || op == '/') return 2; //*, /�� �켱���� 2
	return 0; //������ �����ڴ� �켱���� 0
	//���ÿ� ���� �����ڿ� ���� ���� �����ڸ� ���� �� ���
}

vector<string> infixToPostfix(const string& s) {
	vector<string> out; //out: ���� ����ǥ����� ������ ���� �迭
	stack<char> ops; //ops: ������(+, -, *, /)�� ��ȣ�� ���� ����
	for (size_t i = 0; i < s.size();) { //i: ���� �а� �ִ� ���� ��ġ �ε���
		if (isspace((unsigned char)s[i])) { i++; continue; } //isspace()�� �����̸� true > �ǳʶٱ�

		//���ڰ� ������ ������ �о �ϳ��� ���� ��ū���� ���� �� out�� ���� > ���� �ڸ� �� ó�� ����
		if (isdigit((unsigned char)s[i])) {
			string num;
			while (i < s.size() && isdigit((unsigned char)s[i])) num.push_back(s[i++]);
			out.push_back(num);
		}

		//���� ��ȣ ó�� > (�� ������ ���ÿ� push
		else if (s[i] == '(') {
			ops.push('('); i++;
		}

		//)�� ������ (�� ���� ������ ���ÿ��� pop > out�� �߰�
		//(�� ���� �׷� ���Ҹ� �ϰ� ����ǥ�⿡�� ǥ������ ���� > pop�� ��
		else if (s[i] == ')') {
			while (!ops.empty() && ops.top() != '(') {
				out.push_back(string(1, ops.top())); ops.pop();
			}
			if (ops.empty()) throw runtime_error("��ȣ ����ġ");
			ops.pop();
			i++;
		}

		//�����ڰ� ������ ���� top�� �ִ� �����ڿ� �켱������ ��
		//���ÿ� �ִ� �����ڰ� �� ���ų� ������ pop�ؼ� out�� �ְ�, ���� �����ڸ� push
		//�̷��� �ϸ� 1+2*3�� > 1 2 3 * + ������ ��ȯ��
		else {
			char cur = s[i++];
			if (cur != '+' && cur != '-' && cur != '*' && cur != '/')
				throw runtime_error("�� �� ���� ����");
			while (!ops.empty() && ops.top() != '(' && prec(ops.top()) >= prec(cur)) {
				out.push_back(string(1, ops.top())); ops.pop();
			}
			ops.push(cur);
		}
	}

	//���ڿ��� �� ���� �� ���ÿ� �����ڰ� ���� ������ ���ʴ�� ���� out�� �߰�
	//������ (�� ���������� ��ȣ ����ġ ����
	while (!ops.empty()) {
		if (ops.top() == '(') throw runtime_error("��ȣ ����ġ");
		out.push_back(string(1, ops.top())); ops.pop();
	}
	return out;
}

//pf: ����ǥ��� ��ū �迭
//st: ���� ����(���� ����)
long long evalPostfix(const vector<string>& pf) {
	stack<long long> st;
	for (const string& t : pf) { //���ڴ� �׳� ���ÿ� push, stoll: string > long long ��ȯ
		if (isdigit((unsigned char)t[0])) {
			st.push(stoll(t));
		}

		//�����ڰ� ������ ���ÿ��� �� �� pop(a, b)
		//���� > a = ���� pop�� ��(�� �Ʒ��� �ִ� ��), b = ���߿� pop�� ��(top ��)
		//��: 3 4 - > a=3, b=4 > 3-4=-1
		//���� �� ����� �ٽ� push
		else {
			if (st.size() < 2) throw runtime_error("�ǿ����� ����");
			long long b = st.top(); st.pop();
			long long a = st.top(); st.pop();
			long long r = 0;
			if (t == "+") r = a + b;
			else if (t == "-") r = a - b;
			else if (t == "*") r = a * b;
			else if (t == "/") {
				if (b == 0) throw runtime_error("0���� ���� �� ����");
				r = a / b;           // ���� ������
			}
			else throw runtime_error("�� �� ���� ������");
			st.push(r);
		}
	}

	//���ÿ� ���������� �ϳ��� ���ƾ� �������� ��� ���
	if (st.size() != 1) throw runtime_error("�� ����");
	return st.top();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << "���� ǥ����(����, + - * /, ��ȣ)�� �Է��ϼ���. (��: (2+3)*4 )\n> ";
	string line;
	while (getline(cin, line)) {
		if (line.empty()) break;
		try {
			auto pf = infixToPostfix(line);
			// ���� ���ڿ� ��¿�
			for (size_t i = 0; i < pf.size(); ++i) {
				cout << pf[i] << (i + 1 < pf.size() ? ' ' : '\n');
			}
			cout << "= " << evalPostfix(pf) << "\n";
		}
		catch (const exception& e) {
			cout << "ERROR: " << e.what() << "\n";
		}
		cout << "> ";
	}
	return 0;
}
		
	
