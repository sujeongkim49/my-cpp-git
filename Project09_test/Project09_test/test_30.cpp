/*#include <iostream>
using namespace std;

int solution(int n, int a, int b) {
	int answer = 0;

	do {
		a = (a + 1) / 2; //������ ��ȣ�� ���� ���� ��ȣ�� �����ϴ� ���
		b = (b + 1) / 2;
		++answer; //�� ���尡 ����Ǿ����� ī��Ʈ ����
	} while (a != b); //a, b�� ���� ���忡�� ����.
	//do while �ݺ��� > �ּ� �� �� ����, ������ ������ �˻��� ���̸� �ٽ� �ݺ�

	return answer;
}

int main() {
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	cout << endl;

	int result = solution(n, a, b);

	cout << "������" << a << " ������" << b << " �� " << result << "���忡�� �����ϴ�." << endl;

	return 0;
}*/