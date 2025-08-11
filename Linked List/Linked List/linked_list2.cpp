#include <iostream>
using namespace std;

// 1. 노드 구조체 정의
struct Node {
    int data;     // 데이터를 저장하는 변수
    Node* next;   // 다음 노드를 가리키는 포인터
};

// 2. 연결리스트의 맨 뒤에 새 노드를 추가하는 함수
void append(Node*& head, int value) {
    // 새 노드 동적 생성
    Node* newNode = new Node{ value, NULL };

    // 리스트가 비어있으면 새 노드가 첫 번째 노드가 됨
    if (head == NULL) {
        head = newNode;
        return;
    }

    // 비어있지 않다면 마지막 노드를 찾아서 연결
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // 마지막까지 이동
    }
    temp->next = newNode; // 마지막 노드의 next에 새 노드 주소 저장
}

// 3. 연결리스트를 출력하는 함수
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) { // NULL이 나올 때까지 반복
        cout << temp->data << " -> ";
        temp = temp->next; // 다음 노드로 이동
    }
    cout << "NULL\n"; // 끝 표시
}

// 4. main 함수
int main() {
    Node* head = NULL; // 처음에는 빈 리스트

    // 사용자 입력 받기
    cout << "정수 3개를 입력하세요: ";
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        append(head, num); // 입력받은 숫자를 리스트에 추가
    }

    // 연결리스트 출력
    cout << "연결리스트 출력: ";
    printList(head);

    return 0;
}
