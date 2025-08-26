//인접리스트 이용해서 그래프 구현, 큐를 이용한 너비 우선 탐색 코드(BFS)
/*#include <iostream>
#include <vector>
#include <queue> //큐 사용하기 위해 추가
#include <utility> //pair 사용하기 위해 추가

using namespace std;

// 그래프를 표현하기 위한 인접 리스트 (pair: {목적지, 가중치})
vector<pair<int, int>> adj[8];

//노드의 방문 여부를 기록하기 위한 배열
bool visited[8];

//너비 우선 탐색(BFS)을 수행하는 함수
void bfs(int start_node) {
    //1. BFS에 사용할 큐 생성
    queue<int> q;

    //2. 시작 노드를 큐에 넣고 방문 처리.
    visited[start_node] = true;
    q.push(start_node);

    //3. 큐가 빌 때까지 반복
    while (!q.empty()) {
        //4. 큐에서 가장 앞에 있는 노드를 꺼냄
        int node = q.front();
        q.pop();

        cout << node << " "; //큐에서 꺼낸 순서가 곧 방문 순서

        //5. 꺼낸 노드와 인접한 모든 노드를 확인한다.
        for (const auto& edge : adj[node]) {
            int next_node = edge.first;

            //6. 인접한 노드가 아직 방문하지 않은 노드라면
            if (!visited[next_node]) {
                //7. 그 노드를 방문 처리하고 큐에 넣음
                visited[next_node] = true;
                q.push(next_node);
            }
        }
    }
}

int main() {

    adj[1].push_back({ 2, 5 });
    adj[1].push_back({ 3, 10 });
    adj[3].push_back({ 5, 3 });
    adj[3].push_back({ 6, 2 });
    adj[4].push_back({ 1, 12 });
    adj[6].push_back({ 7, 4 });
    adj[7].push_back({ 4, 7 });

    cout << "너비 우선 탐색(BFS)" << endl;
    cout << "시작 노드: 1" << endl;
    cout << "탐색 순서: ";

    bfs(1); //1번 노드부터 BFS 시작

    cout << endl;

    return 0;
}*/