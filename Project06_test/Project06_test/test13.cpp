#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	if (board.empty() || board[0].empty()) return 0; //�� ���� ó��

	//vector<stack<int>> lanes[board[0].size()];
	//board[0].size()�� ��Ÿ�ӿ��� �� �� �ִ� ��. ������ C++������ ��Ÿ�ӿ� ũ�⸦ �� �� �ִ� ���͸� ����� �� ����.
	//����, board[0].size()�� ��Ÿ�ӿ� �� �� �ִ� ���ͷ� �ʱ�ȭ�ؾ� �Ѵ�. > ���� ũ�� ���� �����̳� vector ���
	vector<stack<int>> lanes;
	for (int i = board.size() - 1; i >= 0; --i) {
		for (int j = 0; j < board[0].size(); ++j) {
			if (board[i][j]) {
				lanes[j].push(board[i][j]);
			}
		}
	}

	stack<int> bucket;
	int answer = 0;

	for (int m : moves) {
		if (lanes[m - 1].size()) { //�ش� ���� ������ ���� �ִ� ���
			int doll = lanes[m - 1].top(); //�� �� ����
			lanes[m - 1].pop(); //����
			if (bucket.size() && bucket.top() == doll) {
				bucket.pop(); //���� ���� ���� > �Ͷ߸�
				answer += 2; //+2
			}
			else {
				bucket.push(doll); //�ٸ� ���� > ��Ŷ�� ����
			}
		}
	}
	return answer;
}