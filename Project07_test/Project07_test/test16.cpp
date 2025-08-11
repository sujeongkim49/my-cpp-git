/*#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

//progresses: �� �۾��� ���� �����, speeds: �� �۾��� �Ϸ� �۾� �ӵ�
//�� �� ���͸� �޾Ƽ� ���� ������ ������ ���� vector<int>�� ��ȯ
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int n = progresses.size(); //�� �۾��� ����
	vector<int> days_left(n); //�� �۾��� �Ϸ�Ǳ���� ���� �ϼ�, days_left[0] > ù ��° �۾��� ���� �ϼ�

	for (int i = 0; i < n; ++i) {
		days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);
		//ceil > ���� ���������� �ø��� ����
		//(���� �۾��� + �ӵ� -1) / �ӵ�
	}

	int count = 0; //���� ���� ������ ���Ե� �۾� ����
	int max_day = days_left[0]; //���� ���� �������� ���� ���� �ɸ��� �۾��� �Ϸ���(���� ������) > ù ��° �۾����� �����ϹǷ� �ʱⰪ�� days_left[0]

	for (int i = 0; i < n; ++i) {
		if (days_left[i] <= max_day) { //���� �۾��� ���� �����Ϻ��� ���� �Ǵ� ���ÿ� �����ٸ�
			count++; //���� ���� ������ ����
		}
		else { //���� �۾��� ���� �����Ϻ��� �ʰ� �����ٸ�
			answer.push_back(count); //���� ���� ������ �۾� ������ ����
			count = 1; //���ο� ������ �����ϹǷ� ���� �ʱ�ȭ
			max_day = days_left[i]; //�� ���� ������ �������� ���� �۾� �Ϸ��Ϸ� ����
		}
	}

	answer.push_back(count);
	return answer;
}*/