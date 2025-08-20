#include <iostream>
#include <vector>
using namespace std;

class Node { //�ϳ��� ��带 ������ ��ü > �� Ŭ���� �ȿ� ��� ��(val), �ڽ�������(left, rignt)�� ����.
public: 
	int val;
	Node* left, * right;

	Node(int key) : val(key), left(nullptr), right(nullptr) {}
	//������, ��ü�� ���� �� �ڵ����� ȣ��Ǵ� �Լ�
	//val�� key ������ �ʱ�ȭ, left, right �����͸� nullptr�� �ʱ�ȭ. > ó������ �ڽ��� ����.
};

class BST { //���� Ž�� Ʈ�� ����
private:
	Node* root; //Ʈ���� ��Ʈ ��Ʈ ������. ��������� nullptr
	Node* insertNode(Node* node, int key) { //��Ϳ� ���� �Լ�
		if (!node) { //���� ����, ���� ��ġ�� ��������� �� ��带 ����� �� �ڸ��� �д�.
			//���⿡�� �ǹ��ϴ� ���� ��ġ > ��� �Լ��� ���� ó�� ���� ���� Ʈ���� ��Ʈ �����͸� �ǹ�.
			//����ִٴ� �� > ��Ʈ�� ��� ���� > root==nullptr
			//�Ǵ�, ��Ʈ�� �ִµ� node->left == nullptr�� insertNode(node->left, key)�� ȣ���ϸ� ���ڷ� nullptr�� �Ѿ��.
			// > �̶��� ���� ��ġ(=�� �ڽ� �ڸ�)�� ����ִٴ� ������ �ǹ� > �� �ڸ��� �� ��带 ����� ����
			return new Node(key); //��(�޸� ����)�� �� ��� �Ҵ�
		}
		if (key < node->val) {
			node->left = insertNode(node->left, key);
		}
		else {
			node->right = insertNode(node->right, key);
		}
		return node;
	}

	bool searchNode(Node* node, int key) { //��Ϳ� ���� �Լ�
		if (!node) {
			return false; //Ʈ���� ����ų� �� ������ ���� ������(�ڽ� ��� X) > ����
		}
		if (key == node->val) { //���� ��尡 ã�� ���̸� ����
			return true;
		}

		return key < node->val ?
			searchNode(node->left, key) :
			searchNode(node->right, key);
	}

	// �ٺ� ����

public:
	BST() : root(nullptr) {} //���� �� Ʈ���� ����ִ� ����
	void insert(int key) { //�ܺο��� ���� �ۺ� api, ���������� ���۸� ȣ��
		root = insertNode(root, key);
	}

	bool search(int key) { //�ܺο��� ���� �ۺ� api, ���������� ���۸� ȣ��
		return searchNode(root, key);
	}
};

vector<bool> solution(vector<int> lst, vector<int> search_lst) {
	BST bst;

	for (int key : lst) {
		bst.insert(key); //����Ʈ�� �� ���� ���ʴ�� Ʈ���� ����
	}

	vector<bool> result;
	for (int search_val : search_lst) {
		result.push_back(bst.search(search_val));
	}

	return result;
}

int main() {
	// ���� �Է�: Ʈ���� ���� ����
	std::vector<int> lst = { 5, 3, 7, 2, 4, 6, 8, 7 }; // 7 �ߺ��� �� �� �־(���� ������ ���������� ������)

	// ���� ����: ���� ���θ� Ȯ���� ����
	std::vector<int> search_lst = { 4, 10, 6, 1, 8, 5, 7 };

	// �ַ�� ����
	std::vector<bool> result = solution(lst, search_lst);

	// ���� ���� true/false�� ���
	std::cout << std::boolalpha;

	std::cout << "[BST ���� ����] ";
	for (int x : lst) std::cout << x << ' ';
	std::cout << "\n";

	std::cout << "[�˻� ���]\n";
	for (std::size_t i = 0; i < search_lst.size(); ++i) {
		std::cout << "  " << search_lst[i] << " -> " << result[i] << "\n";
	}

	return 0;
}
