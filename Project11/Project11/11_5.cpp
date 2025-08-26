//��������Ʈ �̿��ؼ� �׷��� ����, ť�� �̿��� �ʺ� �켱 Ž�� �ڵ�(BFS)
/*#include <iostream>
#include <vector>
#include <queue> //ť ����ϱ� ���� �߰�
#include <utility> //pair ����ϱ� ���� �߰�

using namespace std;

// �׷����� ǥ���ϱ� ���� ���� ����Ʈ (pair: {������, ����ġ})
vector<pair<int, int>> adj[8];

//����� �湮 ���θ� ����ϱ� ���� �迭
bool visited[8];

//�ʺ� �켱 Ž��(BFS)�� �����ϴ� �Լ�
void bfs(int start_node) {
    //1. BFS�� ����� ť ����
    queue<int> q;

    //2. ���� ��带 ť�� �ְ� �湮 ó��.
    visited[start_node] = true;
    q.push(start_node);

    //3. ť�� �� ������ �ݺ�
    while (!q.empty()) {
        //4. ť���� ���� �տ� �ִ� ��带 ����
        int node = q.front();
        q.pop();

        cout << node << " "; //ť���� ���� ������ �� �湮 ����

        //5. ���� ���� ������ ��� ��带 Ȯ���Ѵ�.
        for (const auto& edge : adj[node]) {
            int next_node = edge.first;

            //6. ������ ��尡 ���� �湮���� ���� �����
            if (!visited[next_node]) {
                //7. �� ��带 �湮 ó���ϰ� ť�� ����
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

    cout << "�ʺ� �켱 Ž��(BFS)" << endl;
    cout << "���� ���: 1" << endl;
    cout << "Ž�� ����: ";

    bfs(1); //1�� ������ BFS ����

    cout << endl;

    return 0;
}*/