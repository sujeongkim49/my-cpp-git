#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
using namespace std;

int prec(char op) {
	//prec = 우선순위
	if (op == '+' || op == '-') return 1; //+, -는 우선순위 1
	if (op == '*' || op == '/') return 2; //*, /는 우선순위 2
	return 0; //나머지 연산자는 우선순위 0
	//스택에 쌓인 연산자와 현재 읽은 연산자를 비교할 때 사용
}

vector<string> infixToPostfix(const string& s) {
	vector<string> out; //out: 최종 후위표기식을 저장할 동적 배열
	stack<char> ops; //ops: 연산자(+, -, *, /)와 괄호를 담을 스택
	for (size_t i = 0; i < s.size();) { //i: 현재 읽고 있는 문자 위치 인덱스
		if (isspace((unsigned char)s[i])) { i++; continue; } //isspace()는 공백이면 true > 건너뛰기

		//숫자가 나오면 끝까지 읽어서 하나의 숫자 토큰으로 만든 후 out에 넣음 > 여러 자리 수 처리 가능
		if (isdigit((unsigned char)s[i])) {
			string num;
			while (i < s.size() && isdigit((unsigned char)s[i])) num.push_back(s[i++]);
			out.push_back(num);
		}

		//왼족 괄호 처리 > (는 무조건 스택에 push
		else if (s[i] == '(') {
			ops.push('('); i++;
		}

		//)가 나오면 (을 만날 때까지 스택에서 pop > out에 추가
		//(은 단지 그룹 역할만 하고 후위표기에는 표현되지 않음 > pop만 함
		else if (s[i] == ')') {
			while (!ops.empty() && ops.top() != '(') {
				out.push_back(string(1, ops.top())); ops.pop();
			}
			if (ops.empty()) throw runtime_error("괄호 불일치");
			ops.pop();
			i++;
		}

		//연산자가 들어오면 스택 top에 있는 연산자와 우선순위를 비교
		//스택에 있는 연산자가 더 높거나 같으면 pop해서 out에 넣고, 현재 연산자를 push
		//이렇게 하면 1+2*3이 > 1 2 3 * + 순서로 변환됨
		else {
			char cur = s[i++];
			if (cur != '+' && cur != '-' && cur != '*' && cur != '/')
				throw runtime_error("알 수 없는 문자");
			while (!ops.empty() && ops.top() != '(' && prec(ops.top()) >= prec(cur)) {
				out.push_back(string(1, ops.top())); ops.pop();
			}
			ops.push(cur);
		}
	}

	//문자열을 다 읽은 후 스택에 연산자가 남아 있으면 차례대로 빼서 out에 추가
	//여전히 (가 남아있으면 괄호 불일치 에러
	while (!ops.empty()) {
		if (ops.top() == '(') throw runtime_error("괄호 불일치");
		out.push_back(string(1, ops.top())); ops.pop();
	}
	return out;
}

//pf: 후위표기식 토큰 배열
//st: 계산용 스택(정수 스택)
long long evalPostfix(const vector<string>& pf) {
	stack<long long> st;
	for (const string& t : pf) { //숫자는 그냥 스택에 push, stoll: string > long long 변환
		if (isdigit((unsigned char)t[0])) {
			st.push(stoll(t));
		}

		//연산자가 나오면 스택에서 두 개 pop(a, b)
		//순서 > a = 먼저 pop한 값(더 아래에 있던 값), b = 나중에 pop한 값(top 값)
		//예: 3 4 - > a=3, b=4 > 3-4=-1
		//연산 후 결과를 다시 push
		else {
			if (st.size() < 2) throw runtime_error("피연산자 부족");
			long long b = st.top(); st.pop();
			long long a = st.top(); st.pop();
			long long r = 0;
			if (t == "+") r = a + b;
			else if (t == "-") r = a - b;
			else if (t == "*") r = a * b;
			else if (t == "/") {
				if (b == 0) throw runtime_error("0으로 나눌 수 없음");
				r = a / b;           // 정수 나눗셈
			}
			else throw runtime_error("알 수 없는 연산자");
			st.push(r);
		}
	}

	//스택에 최종적으로 하나만 남아야 정상적인 계산 결과
	if (st.size() != 1) throw runtime_error("평가 실패");
	return st.top();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << "중위 표현식(정수, + - * /, 괄호)을 입력하세요. (예: (2+3)*4 )\n> ";
	string line;
	while (getline(cin, line)) {
		if (line.empty()) break;
		try {
			auto pf = infixToPostfix(line);
			// 후위 문자열 출력용
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
		
	
