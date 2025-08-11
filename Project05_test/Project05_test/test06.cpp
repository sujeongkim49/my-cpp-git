#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector<int> stageCount(N + 2, 0);
	for (int s : stages) {
		stageCount[s]++;
	}
	//���� ��� for���� ����Ͽ� stages ������ �� ���Ҹ� ��ȸ�ϸ鼭 stageCount �迭�� �ش� �ε����� 1�� ������Ŵ

	int totalPlayers = stages.size();
	vector<pair<int, double>> failureRate;

	for (int i = 1; i <= N; i++) {
		if (totalPlayers == 0) {
			failureRate.push_back({ i, 0.0 });
		}
		else {
			double rate = static_cast<double> (stageCount[i]) / totalPlayers;
			failureRate.push_back({ i, rate });
			totalPlayers -= stageCount[i];
		}
	}
	//�ð����⵵ O(N + M)

	sort(failureRate.begin(), failureRate.end(), [](auto& a, auto& b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
		});
	//[] > ĸ�� ����Ʈ(���⼭�� �ƹ��͵� ĸ������ ����)
	//(auto &a, auto &b) > �� ���� �Ű����� (a, b)�� ������ ����. auto�� �� ����: ������ Ÿ���� pair�̶� �ڵ��߷�
	//a.first: �������� ��ȣ(int), a.second: ������(double)

	for (auto& p : failureRate) {
		answer.push_back(p.first);
	}
	//p�� failureRate�� �� ����(pair<int, double>)�� ����
	//p.first�� ������ answer�� �߰�

	return answer;
}*/


/*
vector<double> failureRate(N + 1, 0.0); // �� ���������� �������� ������ ����

	int totalPlayers = stages.size(); // ��ü �÷��̾� ��

	for (int i = 1; i <= N; i++) {
		int reached = count(stages.begin(), stages.end(), i); // ���� ���������� ������ �÷��̾� ��
		if (totalPlayers != 0) {
			failureRate[i] = reached / totalPlayers; // ������ ���
		}
		else {
			failureRate[i] = 0.0; // ���� ���������� ������ �÷��̾ ������ �������� 0
		}
		totalPlayers -= reached; // ���� ���������� ������ �÷��̾� ���� ��ü �÷��̾� ������ ����
	}

	sort(failureRate.rbegin(), failureRate.rend());

	for (int i = 1; i <= N; i++) {
		answer.push_back(failureRate[i].first);
	}
*/
//count() �� �̿��ϸ� �ð����⵵�� O(N*M)�� �Ǳ� ������ ��ȿ����. > O(N+M)���� ����ȭ�ؾ� ��.