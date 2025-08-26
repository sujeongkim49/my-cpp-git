//����-���� �˰������� �ִ� ��� ã��
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

//���� ������ ��� ���� ����ü > tuple�� ����ص� ��
struct Edge {
    int from, to, cost;
};

//�ִ� �Ÿ� ���̺� (���������� �� ��������)
vector<long long> dist;

//��� ���� ������ ���� ����
vector<Edge> edges;

int N; //��� ����
int M; //���� ����

bool bellmanFord(int start) {
    //1. �ִ� �Ÿ� ���̺��� ��� ���Ѵ�� �ʱ�ȭ
    dist.assign(N + 1, INF);

    //2. ���� ����� �Ÿ��� 0���� ����
    dist[start] = 0;

    //3. (��� ���� - 1) �� ��ŭ ��ü ������ ��ȸ�ϸ� �ִ� �Ÿ��� ����
    for (int i = 0; i < N - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.from;
            int v = edge.to;
            int w = edge.cost;

            //������ u���� ������ �����߰� (dist[u] != INF),
            //u�� ���ļ� v�� ���� ���� ������ v������ �Ÿ����� ª�ٸ� ����
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    //4. (��� ����) ��° ��ȸ���� �� ������ �Ͼ���� Ȯ�� > ���� ����Ŭ ����
    for (const auto& edge : edges) {
        int u = edge.from;
        int v = edge.to;
        int w = edge.cost;

        if (dist[u] != INF && dist[v] > dist[u] + w) {
            // (N-1)�� ��ȸ �Ŀ��� �Ÿ��� ª�����ٴ� ���� ���� ����Ŭ�� �����Ѵٴ� �ǹ�
            return false;
        }
    }
    return true; //���� ����Ŭ�� ����
}

int main() {
    N = 5; // 5���� ���
    M = 7; // 7���� ����

    // ���� ���� �߰� (���� ����ġ ����)
    edges.push_back({ 1, 2, 6 });
    edges.push_back({ 1, 3, 7 });
    edges.push_back({ 2, 3, 5 });
    edges.push_back({ 2, 4, -4 }); // ���� ����ġ!
    edges.push_back({ 3, 4, 8 });
    edges.push_back({ 3, 5, -3 }); // ���� ����ġ!
    edges.push_back({ 4, 5, 9 });

    int start_node = 1;
    bool no_negative_cycle = bellmanFord(start_node);

    if (no_negative_cycle) {
        cout << "--- " << start_node << "�� ��忡�� ����ϴ� �ִ� �Ÿ� ---" << endl;
        for (int i = 1; i <= N; ++i) {
            if (dist[i] == INF) {
                cout << i << "�� ���: ������ �� ����" << endl;
            }
            else {
                cout << i << "�� ���: " << dist[i] << endl;
            }
        }
    }
    else {
        cout << "�׷����� ���� ����Ŭ�� �����մϴ�." << endl;
    }

    return 0;
}