//���ͽ�Ʈ�� �˰����� �̿��� �ִ� ��� ã��
/*#include <iostream>
#include <vector>
#include <queue>
#include <utility> //pair

using namespace std;

const int INF = 1e9; // ���Ѵ� ��(10��)

//�׷��� ����. adj[i]�� i�� ��忡�� ����ϴ� �������� ����� ��´�.
//�� ������ pair<int, int> ���·�, {������, ����ġ}�� �ǹ��Ѵ�.
vector<pair<int, int>> adj[7];

//���� ���κ��� �� �������� �ִ� �Ÿ��� ������ �迭
vector<int> d(7);

void dijkstra(int start) {
    //1. �ִ� �Ÿ� ���̺��� ��� ���Ѵ�� �ʱ�ȭ
    d.assign(7, INF);

    //2. �켱���� ť ����. C++�� priority_queue�� �⺻�� max-heap�̹Ƿ�
    //min-heap���� ����ϱ� ���� greater<...>�� �߰����ش�.
    //�켱���� ť���� {�Ÿ�, ��� ��ȣ} ���·� �����Ѵ�.
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //3. ���� ��� ó��
    d[start] = 0; //���� ����� �Ÿ��� 0
    pq.push({ 0, start }); //�켱���� ť�� {0, ���� ���}�� �ִ´�.

    while (!pq.empty()) {
        //4. �켱���� ť���� ���� �Ÿ��� ª�� ��� ������ ������.
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        //5. �̹� ó���� ����� �����Ѵ�.
        //(ť�� �� {�Ÿ�, ���} ������ �ֽ� ������ �ƴ� ���� �ֱ� ����.)
        //�켱���� ť���� ���� ��忡 ���� ������ ���� �� �� �� �ִ�.
        //d�迭���� �׻� �ش� �������� '��������� �ִ� �Ÿ�'�� ��ϵȴ�. ���� ť���� ���� �Ÿ�(dist)�� �̹� ��ϵ� �ִ� �Ÿ��� d[now]���� ũ�ٸ�,
        //�̴� ť�� �� ������ ������ ���̹Ƿ� �����Ѵ�. > continue�� ���� ������ �������� ���ư���.
        if (d[now] < dist) continue;

        //6. ���� ���(now)�� ����� �ٸ� ���� ������ Ȯ���Ѵ�.
        for (const auto& edge : adj[now]) {
            int next = edge.first;
            int weight = edge.second;

            //���� ��带 ���ļ� �ٸ� ���� �̵��ϴ� �Ÿ��� �� ª�� ���
            int cost = d[now] + weight;
            if (cost < d[next]) {
                //7. �ִ� �Ÿ��� �����ϰ�, �켱���� ť�� ���ο� ������ �ִ´�.
                d[next] = cost;
                pq.push({ cost, next });
            }
        }
    }
}

int main() {
    // --- �׷��� ���� (1������ 6�� ��� ���) ---
    adj[1].push_back({ 2, 2 }); // 1->2 (��� 2)
    adj[1].push_back({ 3, 5 }); // 1->3 (��� 5)
    adj[1].push_back({ 4, 1 }); // 1->4 (��� 1)

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

    // ��� ���
    cout << "--- " << start_node << "�� ��忡�� ����ϴ� �ִ� �Ÿ� ---" << endl;
    for (int i = 1; i <= 6; ++i) {
        if (d[i] == INF) {
            cout << i << "�� ���: ������ �� ����" << endl;
        }
        else {
            cout << i << "�� ���: " << d[i] << endl;
        }
    }

    return 0;
}*/