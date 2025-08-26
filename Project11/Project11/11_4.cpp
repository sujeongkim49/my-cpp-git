//��������Ʈ �̿��ؼ� �׷��� ����, ����Լ� �̿��ؼ� DFS ����
//�׷����� ���⼺ ����, ����ġ ����

/*#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> //pair ����ϱ� ���� �߰�

using namespace std;

// �׷����� ǥ���ϱ� ���� ���� ����Ʈ (pair: {������, ����ġ})
vector<pair<int, int>> adj[8];

//����� �湮 ���θ� ����ϱ� ���� �迭
bool visited[8];

//���� �켱 Ž��(DFS)�� �����ϴ� ��� �Լ� (������)
void dfs(int node) {
	//1. ���� ��带 �湮 ó��
	visited[node] = true;
	cout << node << " "; //�湮�� ��� ���

	//2. ���� ���� ������ ��� ����(edge) Ȯ��
	for (const auto& edge : adj[node]) {
		int next_node = edge.first; //������ ���
		int weight = edge.second; //����ġ

		//3. ������ ��尡 ���� �湮���� ���� �����
		if (!visited[next_node]) {
			dfs(next_node); //�� ���� �̵��ؼ� DFS ��� ����(��� ȣ��)
		}
	}

}

int main() {
    // --- ����� ����ġ�� �ִ� �׷��� ���� ---
    // 1 -> 2 (5)
    // ^ \
    // |  v
    // 4  3 -> 5 (3)
    // ^  |
    // |  v
    // 7 <- 6 (2)

    // adj[A].push_back({B, W}); �� A���� B�� ���� ����ġ W�� ������ �ִٴ� �ǹ�

    // 1�� ��忡�� ������ ������
    adj[1].push_back({ 2, 5 });
    adj[1].push_back({ 3, 10 });

    // 2�� ��忡�� ������ ������
    // (���⼺�� �����Ƿ� 2->1 ������ ������ �߰����� ������ ����)

    // 3�� ��忡�� ������ ������
    adj[3].push_back({ 5, 3 });
    adj[3].push_back({ 6, 2 });

    // 4�� ��忡�� ������ ������
    adj[4].push_back({ 1, 12 }); // 4 -> 1

    // 5�� ��忡�� ������ ������
    // (���ٸ� ��)

    // 6�� ��忡�� ������ ������
    adj[6].push_back({ 7, 4 });

    // 7�� ��忡�� ������ ������
    adj[7].push_back({ 4, 7 });

    std::cout << "����/����ġ �׷����� ���� �켱 Ž��(DFS)" << std::endl;
    std::cout << "���� ���: 1" << std::endl;
    std::cout << "Ž�� ����: ";

    // 1�� ������ DFS ����
    dfs(1);

    std::cout << std::endl;

    return 0;
}*/