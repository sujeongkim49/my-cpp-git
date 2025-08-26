//다익스트라 알고리즘을 이용한 최단 경로 찾기
/*#include <iostream>
#include <vector>
#include <queue>
#include <utility> //pair

using namespace std;

const int INF = 1e9; // 무한대 값(10억)

//그래프 정보. adj[i]는 i번 노드에서 출발하는 간선들의 목록을 담는다.
//각 간선은 pair<int, int> 형태로, {도착지, 가중치}를 의미한다.
vector<pair<int, int>> adj[7];

//시작 노드로부터 각 노드까지의 최단 거리를 저장할 배열
vector<int> d(7);

void dijkstra(int start) {
    //1. 최단 거리 테이블을 모두 무한대로 초기화
    d.assign(7, INF);

    //2. 우선순위 큐 생성. C++의 priority_queue는 기본이 max-heap이므로
    //min-heap으로 사용하기 위해 greater<...>를 추가해준다.
    //우선순위 큐에는 {거리, 노드 번호} 형태로 저장한다.
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //3. 시작 노드 처리
    d[start] = 0; //시작 노드의 거리는 0
    pq.push({ 0, start }); //우선순위 큐에 {0, 시작 노드}를 넣는다.

    while (!pq.empty()) {
        //4. 우선순위 큐에서 가장 거리가 짧은 노드 정보를 꺼낸다.
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        //5. 이미 처리된 노드라면 무시한다.
        //(큐에 들어간 {거리, 노드} 정보가 최신 정보가 아닐 수도 있기 때문.)
        //우선순위 큐에는 같은 노드에 대한 정보가 여러 번 들어갈 수 있다.
        //d배열에는 항상 해당 노드까지의 '현재까지의 최단 거리'만 기록된다. 따라서 큐에서 꺼낸 거리(dist)가 이미 기록된 최단 거리인 d[now]보다 크다면,
        //이는 큐에 들어간 정보가 오래된 것이므로 무시한다. > continue를 통해 루프의 시작으로 돌아간다.
        if (d[now] < dist) continue;

        //6. 현재 노드(now)와 연결된 다른 인접 노드들을 확인한다.
        for (const auto& edge : adj[now]) {
            int next = edge.first;
            int weight = edge.second;

            //현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            int cost = d[now] + weight;
            if (cost < d[next]) {
                //7. 최단 거리를 갱신하고, 우선순위 큐에 새로운 정보를 넣는다.
                d[next] = cost;
                pq.push({ cost, next });
            }
        }
    }
}

int main() {
    // --- 그래프 생성 (1번부터 6번 노드 사용) ---
    adj[1].push_back({ 2, 2 }); // 1->2 (비용 2)
    adj[1].push_back({ 3, 5 }); // 1->3 (비용 5)
    adj[1].push_back({ 4, 1 }); // 1->4 (비용 1)

    adj[2].push_back({ 3, 3 });
    adj[2].push_back({ 4, 2 });

    adj[3].push_back({ 2, 3 });
    adj[3].push_back({ 6, 5 });

    adj[4].push_back({ 3, 3 });
    adj[4].push_back({ 5, 1 });

    adj[5].push_back({ 3, 1 });
    adj[5].push_back({ 6, 2 });

    int start_node = 1;
    dijkstra(start_node);

    // 결과 출력
    cout << "--- " << start_node << "번 노드에서 출발하는 최단 거리 ---" << endl;
    for (int i = 1; i <= 6; ++i) {
        if (d[i] == INF) {
            cout << i << "번 노드: 도달할 수 없음" << endl;
        }
        else {
            cout << i << "번 노드: " << d[i] << endl;
        }
    }

    return 0;
}*/