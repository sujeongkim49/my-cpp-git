//������ ����� ���� �켱 Ž��(DFS)
/*#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//��� 1~5���� �ִٰ� ����
int main() {
	int numNodes = 5;

	//���� ����Ʈ(������ �׷��� ����)
	vector<vector<int>> adj(numNodes + 1);

	//���� �߰�
	adj[1] = { 2,3 };
	adj[2] = { 1,4};
	adj[3] = { 1, 5 };
	adj[4] = { 2 };
	adj[5] = { 3 };

	vector<bool> visited(numNodes + 1, false); //�湮 ���� üũ
	stack<int> st; //����

	int start = 1; //1�� ��忡�� ����
	st.push(start);

	cout << "DFS �湮 ����: ";

	while (!st.empty()) {
		int cur = st.top();
		st.pop();

		if (visited[cur]) continue; //�̹� �湮������ �н�
		visited[cur] = true; //�湮 ó��

		cout << cur << " "; //���� �湮 ���

		//���� ��� ���ÿ� �߰�(�������� �߰��Ͽ� ���� ��ȣ���� �湮)
		for (int i = adj[cur].size() - 1; i >= 0; i--) {
			int nxt = adj[cur][i];
			if (!visited[nxt]) {
				st.push(nxt);
			}
		}
	}

	cout << endl;
	return 0;
}*/