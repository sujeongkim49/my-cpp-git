/*#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	answer.assign(arr1.size(), vector<int>(arr2[1].size(), 0)); //arr1�� arr2�� ��� ���� �������� �� ���� ����� ũ�⸸ŭ ������ �Ҵ�
	//��� ���� ��Ģ : A(m x n) * B(n x p) = C(m x p), ��, ��� ���� ���� = arr1�� �� ���� arr1.size(), ��� ���� ���� = arr2�� �� ���� arr2[0].size() �Ǵ� arr2[1].size()
	//assign() ���� : answer.assign(�� ����, vector<int>(�� ����, �ʱⰪ))
	//answer�� �� ������ŭ �����, �� ���� �� ������ŭ�� int�� 0���� �ʱ�ȭ.
	//��� �� ����� ũ�⸦ �̸� �˾ƾ�, ����, ���� for������ �ε����� �����ϰ� ���� ����.
	//answer[i][j] +=... ���� ���� ������ �Ϸ��� ó���� 0���� �ʱ�ȭ�� ������ ������ �ʿ�.
	//push_back()�� �ݺ��� �ȿ��� ���� ���ʿ��� �޸� ���Ҵ��� �߻��ϰ� �ڵ尡 ��������.

	for (int i = 0; i < arr1.size(); i++) {
		for (int j = 0; j < arr2[1].size(); j++) {
			for (int k = 0; k < arr2.size(); k++) {
				answer[i][j] += arr1[i][k] * arr2[k][j]; //��� ���� ����: C[i][j] = A[i][k] * B[k][j]
			}
		}
	}

	return answer;
}*/