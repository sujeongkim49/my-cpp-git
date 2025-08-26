//벨만-포드 알고리즘으로 최단 경로 찾기
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

//간선 정보를 담기 위한 구조체 > tuple을 사용해도 됨
struct Edge {
    int from, to, cost;
};

//최단 거리 테이블 (시작점에서 각 노드까지의)
vector<long long> dist;

//모든 간선 정보를 담을 벡터
vector<Edge> edges;

int N; //노드 개수
int M; //간선 개수

bool bellmanFord(int start) {
    //1. 최단 거리 테이블을 모두 무한대로 초기화
    dist.assign(N + 1, INF);

    //2. 시작 노드의 거리는 0으로 설정
    dist[start] = 0;

    //3. (노드 개수 - 1) 번 만큼 전체 간선을 순회하며 최단 거리를 갱신
    for (int i = 0; i < N - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int w = edge.cost;

            //시작점 u까지 도달이 가능했고 (dist[u] != INF),
            //u를 거쳐서 v로 가는 것이 기존의 v까지의 거리보다 짧다면 갱신
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    //4. (노드 개수) 번째 순회에서 또 갱신이 일어나는지 확인 > 음수 사이클 감지
    for (const auto& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int w = edge.cost;

        if (dist[u] != INF && dist[v] > dist[u] + w) {
            // (N-1)번 순회 후에도 거리가 짧아진다는 것은 음수 사이클이 존재한다는 의미
            return false;
        }
    }
    return true; //음수 사이클이 없음
}

int main() {
    N = 5; // 5개의 노드
    M = 7; // 7개의 간선

    // 간선 정보 추가 (음수 가중치 포함)
    edges.push_back({ 1, 2, 6 });
    edges.push_back({ 1, 3, 7 });
    edges.push_back({ 2, 3, 5 });
    edges.push_back({ 2, 4, -4 }); // 음수 가중치!
    edges.push_back({ 3, 4, 8 });
    edges.push_back({ 3, 5, -3 }); // 음수 가중치!
    edges.push_back({ 4, 5, 9 });

    int start_node = 1;
    bool no_negative_cycle = bellmanFord(start_node);

    if (no_negative_cycle) {
        cout << "--- " << start_node << "번 노드에서 출발하는 최단 거리 ---" << endl;
        for (int i = 1; i <= N; ++i) {
            if (dist[i] == INF) {
                cout << i << "번 노드: 도달할 수 없음" << endl;
            }
            else {
                cout << i << "번 노드: " << dist[i] << endl;
            }
        }
    }
    else {
        cout << "그래프에 음수 사이클이 존재합니다." << endl;
    }

    return 0;
}