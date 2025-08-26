//스택을 사용한 깊이 우선 탐색(DFS)
/*#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//노드 1~5까지 있다고 가정
int main() {
	int numNodes = 5;

	//인접 리스트(무방향 그래프 예시)
	vector<vector<int>> adj(numNodes + 1);

	//간선 추가
	adj[1] = { 2,3 };
	adj[2] = { 1,4};
	adj[3] = { 1, 5 };
	adj[4] = { 2 };
	adj[5] = { 3 };

	vector<bool> visited(numNodes + 1, false); //방문 여부 체크
	stack<int> st; //스택

	int start = 1; //1번 노드에서 시작
	st.push(start);

	cout << "DFS 방문 순서: ";

	while (!st.empty()) {
		int cur = st.top();
		st.pop();

		if (visited[cur]) continue; //이미 방문했으면 패스
		visited[cur] = true; //방문 처리

		cout << cur << " "; //현재 방문 노드

		//인접 노드 스택에 추가(역순으로 추가하여 작은 번호부터 방문)
		for (int i = adj[cur].size() - 1; i >= 0; i--) {
			int nxt = adj[cur][i];
			if (!visited[nxt]) {
				st.push(nxt);
			}
		}
	}

	cout << endl;
	return 0;
}*/