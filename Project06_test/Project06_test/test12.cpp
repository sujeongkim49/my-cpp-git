/*#include <vector>
#include <stack>
#include <string>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	//ũ�Ⱑ price.size()�� ���͸� ����� ��� ���Ҹ� �⺻��(0)���� �ʱ�ȭ�Ѵ�. > (int�� �⺻���� 0)
	stack<int> s;

	int priceNum = prices.size();
	//�ݺ������� ���� �� prices.size()�� ȣ���ϴ� ���� �����ϱ� ���� ������ �����Ѵ�. > ���� �̼� ����ȭ

	for (int i = 0; i < priceNum; i++) {
		while (!s.empty() && prices[s.top()] > prices[i]) {
			answer[s.top()] = i - s.top();
			//���� �Ⱓ = ������ ���� �ε��� - ���� ���� �ε���
			s.pop();
			//�̹� ������ ������ ���� �Ⱓ�� ��������Ƿ� ���ÿ��� ����
		}
		s.push(i);
		//���� ���� �ε����� ���ÿ� ����
	}

	while (!s.empty()) {
		answer[s.top()] = priceNum - s.top() - 1;
		s.pop();
		//������ ������ �������� ���� ���, ���� �Ⱓ = ������ �ε��� - ���� ���� �ε���
		//��� ���� �ε����� ���� ��� �� ���� ���.
	}
	return answer;
}*/