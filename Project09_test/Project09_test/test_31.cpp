#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int>amount) {
	//enroll:��ϵ� �Ǹſ��� �̸� ���, referral: �� �Ǹſ��� ��õ��(������), ������ "-", seller: �Ǹ��� ������� �̸� ���, amount: �Ǹ��� ���� ����
	unordered_map<string, string> parent;
	//parent[name] = ��õ�� ���踦 �����ϴ� �ؽø�
	//��: john -> mary

	for (size_t i = 0; i < enroll.size(); ++i) {
		parent[enroll[i]] = referral[i];
	}
	//��� �Ǹſ��� ���� �ڽ��� ��õ���� parent�� ���.

	unordered_map<string, int> total;
	for (const auto& name : enroll) {
		total[name] = 0;
	}
	//�� �Ǹſ��� ������ ����� �ؽø� total > 0�� �ʱ�ȭ.

	for (size_t i = 0; i < seller.size(); ++i) {
		int money = amount[i] * 100;
		string cur_name = seller[i];
		//cur_name > ���� �Ǹ� ���� �Ǹſ��� �̸�
		
		while (money > 0 && cur_name != "-") {
			int to_distribute = money / 10;
			total[cur_name] += money - to_distribute;
			//�Ǹſ��� 90��ŭ ������ �������� 10%�� ��õ�ο��� �ѱ�.

			if (parent.find(cur_name) != parent.end()) {
				cur_name = parent[cur_name]; //��õ���� �����Ѵٸ� cur_name�� �θ�� ���� -> ���� �ܰ�� �̵�
			}
			else { break; }
			money = to_distribute;
		}
	}

	vector<int> result;
	result.reserve(enroll.size());
	for (const auto& name : enroll) {
		result.push_back(total[name]);
	}

	return result;
}

int main() {
	// ��ϵ� �Ǹſ�
	vector<string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
	// ��õ�� (������ "-")
	vector<string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };

	// �̹� �Ǹ���
	vector<string> seller = { "young", "john", "tod", "emily", "mary" };
	// �Ǹ� ����
	vector<int> amount = { 12, 4, 2, 5, 10 };

	// �ַ�� ȣ��
	vector<int> result = solution(enroll, referral, seller, amount);

	// ���
	cout << "[���� ���� ���]\n";
	for (size_t i = 0; i < enroll.size(); ++i) {
		cout << enroll[i] << " : " << result[i] << "\n";
	}

	return 0;
}

//i++�� ��� �� ���� ���纻�� �����, �� ������ ������Ű�� ������ ����, �ݸ� ++i�� ���� ���� �ٷ� ���� ����
//�Ϲ� Ÿ�Կ����� ���̰� ������, ���ͷ�����(iterator)���� ������ ��ü������ i++�� ���ʿ��� ���縦 ���� �� �ֱ� ������ ���������� ++i�� ���� ���� �� ����.