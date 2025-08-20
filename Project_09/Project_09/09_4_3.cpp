#include <iostream>
#include <vector>
using namespace std;

class Node { //하나의 노드를 포현할 객체 > 이 클래스 안에 노드 값(val), 자식포인터(left, rignt)가 들어간다.
public: 
	int val;
	Node* left, * right;

	Node(int key) : val(key), left(nullptr), right(nullptr) {}
	//생성자, 객체를 만들 때 자동으로 호출되는 함수
	//val을 key 값으로 초기화, left, right 포인터를 nullptr로 초기화. > 처음에는 자식이 없음.
};

class BST { //이진 탐색 트리 구현
private:
	Node* root; //트리의 루트 노트 포인터. 비어있으면 nullptr
	Node* insertNode(Node* node, int key) { //재귀용 헬퍼 함수
		if (!node) { //기저 조건, 현재 위치가 비어있으면 새 노드를 만들어 그 자리에 둔다.
			//여기에서 의미하는 현재 위치 > 재귀 함수가 지금 처리 중인 서브 트리의 루트 포인터를 의미.
			//비어있다는 것 > 루트가 비어 있음 > root==nullptr
			//또는, 루트는 있는데 node->left == nullptr라서 insertNode(node->left, key)를 호출하면 인자로 nullptr이 넘어옴.
			// > 이때도 현재 위치(=그 자식 자리)가 비어있다는 뜻으로 의미 > 그 자리에 새 노드를 만들어 연결
			return new Node(key); //힙(메모리 공간)에 새 노드 할당
		}
		if (key < node->val) {
			node->left = insertNode(node->left, key);
		}
		else {
			node->right = insertNode(node->right, key);
		}
		return node;
	}

	bool searchNode(Node* node, int key) { //재귀용 헬퍼 함수
		if (!node) {
			return false; //트리가 비었거나 더 내려갈 곳이 없으면(자식 노드 X) > 실패
		}
		if (key == node->val) { //현재 노드가 찾는 값이면 성공
			return true;
		}

		return key < node->val ?
			searchNode(node->left, key) :
			searchNode(node->right, key);
	}

	// 바보 ㅋㅋ

public:
	BST() : root(nullptr) {} //생성 시 트리는 비어있는 상태
	void insert(int key) { //외부에서 쓰는 퍼블릭 api, 내부적으로 헬퍼를 호출
		root = insertNode(root, key);
	}

	bool search(int key) { //외부에서 쓰는 퍼블릭 api, 내부적으로 헬퍼를 호출
		return searchNode(root, key);
	}
};

vector<bool> solution(vector<int> lst, vector<int> search_lst) {
	BST bst;

	for (int key : lst) {
		bst.insert(key); //리스트의 각 값을 차례대로 트리에 삽입
	}

	vector<bool> result;
	for (int search_val : search_lst) {
		result.push_back(bst.search(search_val));
	}

	return result;
}

int main() {
	// 예시 입력: 트리에 넣을 값들
	std::vector<int> lst = { 5, 3, 7, 2, 4, 6, 8, 7 }; // 7 중복도 한 번 넣어봄(현재 구현은 오른쪽으로 내려감)

	// 예시 질의: 존재 여부를 확인할 값들
	std::vector<int> search_lst = { 4, 10, 6, 1, 8, 5, 7 };

	// 솔루션 실행
	std::vector<bool> result = solution(lst, search_lst);

	// 보기 좋게 true/false로 출력
	std::cout << std::boolalpha;

	std::cout << "[BST 삽입 값들] ";
	for (int x : lst) std::cout << x << ' ';
	std::cout << "\n";

	std::cout << "[검색 결과]\n";
	for (std::size_t i = 0; i < search_lst.size(); ++i) {
		std::cout << "  " << search_lst[i] << " -> " << result[i] << "\n";
	}

	return 0;
}
