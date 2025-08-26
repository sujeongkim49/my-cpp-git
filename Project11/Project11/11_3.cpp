//인접리스트 이용해서 그래프 구현, 재귀함수 이용해서 DFS 구현

/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 그래프를 표현하기 위한 인접 리스트
// vector<int> adj[N]은 N개의 연결된 노드를 가지는 그래프를 의미하며,
// adj[i]는 i번 노드에 연결된 노드들의 목록을 담는 vector이다.

vector<int> adj[8];

//노드의 방문 여부를 기록하기 위한 배열
bool visited[8];

//깊이 우선 탐색(DFS)을 수행하는 재귀 함수
void dfs(int node) {
	//1. 현재 노드를 방문 처리
	visited[node] = true;
	cout << node << " "; //방문한 노드 출력

	//2. 현재 노드와 인접한 모든 노드를 확인
	for (int i = 0; i < adj[node].size(); ++i) {
		int next_node = adj[node][i];

		//3. 인접한 노드가 아직 방문하지 않은 노드라면
		if (!visited[next_node]) {
			//그 노드로 이동해서 DFS 계속 진행(재귀 호출)
			dfs(next_node);
		}
	}
	//4. 더 이상 방문할 인접 노드가 없으면 함수가 종료되고, 이전 노드로 돌아간다.
}

int main() {
	// --- 그래프 생성 (연결 관계 설정) ---
	//    1
	//   / \
    //  2   3
	// / \   \
    // 4  5 - 6
	// \ /
	//  7

	//1번 노드와 연결된 노드들
	adj[1].push_back(2);
	adj[1].push_back(3);

	//2번 노드와 연결된 노드들
	adj[2].push_back(1);
	adj[2].push_back(4);
	adj[2].push_back(5);

	//3번 노드와 연결된 노드들
	adj[3].push_back(1);
	adj[3].push_back(6);

	//4번 노드와 연결된 노드들
	adj[4].push_back(2);
	adj[4].push_back(7);

	//5번 노드와 연결된 노드들
	adj[5].push_back(2);
	adj[5].push_back(6);
	adj[5].push_back(7);

	//6번 노드와 연결된 노드들
	adj[6].push_back(3);
	adj[6].push_back(5);

	//7번 노드와 연결된 노드들
	adj[7].push_back(4);
	adj[7].push_back(5);

	//인접 리스트를 정렬하여 항상 같은 순서로 탐색하도록 보장 (선택)
	for (int i = 1; i < 8; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}

	cout << "깊이 우선 탐색(DFS) 시작 노드: 1" << endl;
	cout << "탐색 순서: ";

	dfs(1);

	cout << endl;

	return 0;
}*/