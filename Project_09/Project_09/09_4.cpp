/*#include <iostream>
#include <vector>
using namespace std;

void preOrder(const vector<int>& nodes, int idx) {
	if (idx >= nodes.size()) return;

	cout << nodes[idx] << " ";
	preOrder(nodes, 2 * idx + 1); //�ε����� 0���� �����ϴ� ���, ���� �ڽ� ���
	preOrder(nodes, 2 * idx + 2); //������ �ڽ� ���
}

int main() {
	vector<int> tree = { 1,2,3,4,5,6,7 };

	cout << "Preorder Traversal: ";
	preOrder(tree, 0);
	cout << endl;

	return 0;
}*/