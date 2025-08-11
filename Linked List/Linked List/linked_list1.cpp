/*#include <iostream>
using namespace std;

// 노드 구조체 정의
struct Node {
    int data;      // 데이터
    Node* next;    // 다음 노드를 가리키는 포인터
};

// 연결리스트에 노드 추가 (맨 뒤)
void append(Node*& head, int value) {
    Node* newNode = new Node{ value, NULL };
    if (head == NULL) { // 리스트가 비었을 때
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) { // 마지막 노드까지 이동
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 연결리스트 출력
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL; // 빈 리스트 시작

    append(head, 10);
    append(head, 20);
    append(head, 30);

    printList(head); // 출력: 10 -> 20 -> 30 -> NULL

    return 0;
}*/
