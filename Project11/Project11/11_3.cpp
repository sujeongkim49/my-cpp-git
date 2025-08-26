//��������Ʈ �̿��ؼ� �׷��� ����, ����Լ� �̿��ؼ� DFS ����

/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �׷����� ǥ���ϱ� ���� ���� ����Ʈ
// vector<int> adj[N]�� N���� ����� ��带 ������ �׷����� �ǹ��ϸ�,
// adj[i]�� i�� ��忡 ����� ������ ����� ��� vector�̴�.

vector<int> adj[8];

//����� �湮 ���θ� ����ϱ� ���� �迭
bool visited[8];

//���� �켱 Ž��(DFS)�� �����ϴ� ��� �Լ�
void dfs(int node) {
	//1. ���� ��带 �湮 ó��
	visited[node] = true;
	cout << node << " "; //�湮�� ��� ���

	//2. ���� ���� ������ ��� ��带 Ȯ��
	for (int i = 0; i < adj[node].size(); ++i) {
		int next_node = adj[node][i];

		//3. ������ ��尡 ���� �湮���� ���� �����
		if (!visited[next_node]) {
			//�� ���� �̵��ؼ� DFS ��� ����(��� ȣ��)
			dfs(next_node);
		}
	}
	//4. �� �̻� �湮�� ���� ��尡 ������ �Լ��� ����ǰ�, ���� ���� ���ư���.
}

int main() {
	// --- �׷��� ���� (���� ���� ����) ---
	//    1
	//   / \
    //  2   3
	// / \   \
    // 4  5 - 6
	// \ /
	//  7

	//1�� ���� ����� ����
	adj[1].push_back(2);
	adj[1].push_back(3);

	//2�� ���� ����� ����
	adj[2].push_back(1);
	adj[2].push_back(4);
	adj[2].push_back(5);

	//3�� ���� ����� ����
	adj[3].push_back(1);
	adj[3].push_back(6);

	//4�� ���� ����� ����
	adj[4].push_back(2);
	adj[4].push_back(7);

	//5�� ���� ����� ����
	adj[5].push_back(2);
	adj[5].push_back(6);
	adj[5].push_back(7);

	//6�� ���� ����� ����
	adj[6].push_back(3);
	adj[6].push_back(5);

	//7�� ���� ����� ����
	adj[7].push_back(4);
	adj[7].push_back(5);

	//���� ����Ʈ�� �����Ͽ� �׻� ���� ������ Ž���ϵ��� ���� (����)
	for (int i = 1; i < 8; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}

	cout << "���� �켱 Ž��(DFS) ���� ���: 1" << endl;
	cout << "Ž�� ����: ";

	dfs(1);

	cout << endl;

	return 0;
}*/