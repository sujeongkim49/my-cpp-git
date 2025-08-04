#include <stack>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	if (board.empty() || board[0].empty()) return 0; //빈 보드 처리

	//vector<stack<int>> lanes[board[0].size()];
	//board[0].size()는 런타임에만 알 수 있는 값. 하지만 C++에서는 런타임에 크기를 알 수 있는 벡터를 사용할 수 없다.
	//따라서, board[0].size()를 런타임에 알 수 있는 벡터로 초기화해야 한다. > 동적 크기 지원 컨테이너 vector 사용
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
		if (lanes[m - 1].size()) { //해당 열에 인형이 남아 있는 경우
			int doll = lanes[m - 1].top(); //맨 위 인형
			lanes[m - 1].pop(); //꺼냄
			if (bucket.size() && bucket.top() == doll) {
				bucket.pop(); //같은 인형 연속 > 터뜨림
				answer += 2; //+2
			}
			else {
				bucket.push(doll); //다른 인형 > 버킷에 넣음
			}
		}
	}
	return answer;
}