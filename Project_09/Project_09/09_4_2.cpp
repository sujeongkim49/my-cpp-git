/*#include <iostream>
#include <vector>
#include <string>
using namespace std;

string preOrder(vector<int> nodes, int idx) {
	if (idx >= nodes.size()) return " ";
	

	string tree = to_string(nodes[idx]) + " ";
	tree += preOrder(nodes, idx * 2 + 1);
	tree += preOrder(nodes, idx * 2 + 2);
	return tree;

}

string inOrder(vector<int> nodes, int idx) {
	if (idx >= nodes.size()) return " ";

	string tree = inOrder(nodes, idx * 2 + 1);
	tree += to_string(nodes[idx]) + " ";
	tree += inOrder(nodes, idx * 2 + 2);

	return tree;
}

string postOrder(vector<int> nodes, int idx) {
	if (idx >= nodes.size()) return " ";

	string tree = postOrder(nodes, idx * 2 + 1);
	tree += postOrder(nodes, idx * 2 + 2);
	tree += to_string(nodes[idx]) + " ";

	return tree;
}

vector<string> solution(vector<int> nodes) {
	vector<string> result;
	string pre = preOrder(nodes, 0);
	string in = inOrder(nodes, 0);
	string post = postOrder(nodes, 0);

	result.push_back(pre);
	result.push_back(in);
	result.push_back(post);

	return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> nodes(n);
	
	cout << n << "개의 노드 값을 입력하시오";
	for (int i = 0; i < n; i++) {
		cin >> nodes[i];
	}

	cout << endl;

	vector<string> result = solution(nodes);
	cout << "Preorder: " << result[0] << endl;
	cout << "Inorder: " << result[1] << endl;
	cout << "Postorder: " << result[2] << endl;
	
	return 0;
}*/