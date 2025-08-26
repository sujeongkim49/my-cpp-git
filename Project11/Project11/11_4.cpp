//인접리스트 이용해서 그래프 구현, 재귀함수 이용해서 DFS 구현
//그래프에 방향성 있음, 가중치 구현

/*#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> //pair 사용하기 위해 추가

using namespace std;

// 그래프를 표현하기 위한 인접 리스트 (pair: {목적지, 가중치})
vector<pair<int, int>> adj[8];

//노드의 방문 여부를 기록하기 위한 배열
bool visited[8];

//깊이 우선 탐색(DFS)을 수행하는 재귀 함수 (수정됨)
void dfs(int node) {
	//1. 현재 노드를 방문 처리
	visited[node] = true;
	cout << node << " "; //방문한 노드 출력

	//2. 현재 노드와 인접한 모든 간선(edge) 확인
	for (const auto& edge : adj[node]) {
		int next_node = edge.first; //목적지 노드
		int weight = edge.second; //가중치

		//3. 인접한 노드가 아직 방문하지 않은 노드라면
		if (!visited[next_node]) {
			dfs(next_node); //그 노드로 이동해서 DFS 계속 진행(재귀 호출)
		}
	}

}

int main() {
    // --- 방향과 가중치가 있는 그래프 생성 ---
    // 1 -> 2 (5)
    // ^ \
    // |  v
    // 4  3 -> 5 (3)
    // ^  |
    // |  v
    // 7 <- 6 (2)

    // adj[A].push_back({B, W}); 는 A에서 B로 가는 가중치 W의 간선이 있다는 의미

    // 1번 노드에서 나가는 간선들
    adj[1].push_back({ 2, 5 });
    adj[1].push_back({ 3, 10 });

    // 2번 노드에서 나가는 간선들
    // (방향성이 있으므로 2->1 간선은 별도로 추가하지 않으면 없음)

    // 3번 노드에서 나가는 간선들
    adj[3].push_back({ 5, 3 });
    adj[3].push_back({ 6, 2 });

    // 4번 노드에서 나가는 간선들
    adj[4].push_back({ 1, 12 }); // 4 -> 1

    // 5번 노드에서 나가는 간선들
    // (막다른 길)

    // 6번 노드에서 나가는 간선들
    adj[6].push_back({ 7, 4 });

    // 7번 노드에서 나가는 간선들
    adj[7].push_back({ 4, 7 });

    std::cout << "방향/가중치 그래프의 깊이 우선 탐색(DFS)" << std::endl;
    std::cout << "시작 노드: 1" << std::endl;
    std::cout << "탐색 순서: ";

    // 1번 노드부터 DFS 시작
    dfs(1);

    std::cout << std::endl;

    return 0;
}*/