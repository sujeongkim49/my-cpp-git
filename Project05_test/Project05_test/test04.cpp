/*#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> firstPattern = { 1, 2, 3, 4, 5 }; //1�� ������
vector<int> secondPattern = { 2,1, 2, 3, 2, 4, 2, 5 }; //2�� ������
vector<int> thirdPattern = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; //3�� ������
// ���� �ݺ��Ǵ� �����̹Ƿ�, ���� ������ ª�Ƶ� %������ ���� ��ȯ ����

vector<int> solution(vector<int> answers) {
	vector<int> answer; //���� ������ ���� �迭

	vector<int> matchCnt(3); //���� ���� ���� �������� ��ȣ�� ����

	for (int i = 0; i < answers.size(); i++) {	//��� ������ �ϳ��� Ȯ��
		if (answers[i] == firstPattern[i % firstPattern.size()]) {
			matchCnt[0]++;
		}
		if (answers[i] == secondPattern[i % secondPattern.size()]) {
			matchCnt[1]++;
		}
		if (answers[i] == thirdPattern[i % thirdPattern.size()]) {
			matchCnt[2]++;
		}
	}

	int max_score = *max_element(matchCnt.begin(), matchCnt.end()); //max_element() > ���� ������ ���� ū ������ �ݺ��ڸ� ��ȯ
	//*���� �������ؼ� ��(���� ������ �ִ� ����)�� ����

	for (int i = 0; i < matchCnt.size(); i++) {
		if (matchCnt[i] == max_score) {
			answer.push_back(i + 1); // 1, 2, 3�� ������
		}
	}

	return answer;
}*/