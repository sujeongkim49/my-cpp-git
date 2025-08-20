/*#include <iostream>
#include <vector>
using namespace std;

void preOrder(const vector<int>& nodes, int idx) {
	if (idx >= nodes.size()) return;

	cout << nodes[idx] << " ";
	preOrder(nodes, 2 * idx + 1); //인덱스를 0부터 시작하는 경우, 왼쪽 자식 노드
	preOrder(nodes, 2 * idx + 2); //오른쪽 자식 노드
}

int main() {
	vector<int> tree = { 1,2,3,4,5,6,7 };

	cout << "Preorder Traversal: ";
	preOrder(tree, 0);
	cout << endl;

	return 0;
}*/