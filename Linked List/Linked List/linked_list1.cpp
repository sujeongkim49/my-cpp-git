/*#include <iostream>
using namespace std;

// ��� ����ü ����
struct Node {
    int data;      // ������
    Node* next;    // ���� ��带 ����Ű�� ������
};

// ���Ḯ��Ʈ�� ��� �߰� (�� ��)
void append(Node*& head, int value) {
    Node* newNode = new Node{ value, NULL };
    if (head == NULL) { // ����Ʈ�� ����� ��
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) { // ������ ������ �̵�
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// ���Ḯ��Ʈ ���
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL; // �� ����Ʈ ����

    append(head, 10);
    append(head, 20);
    append(head, 30);

    printList(head); // ���: 10 -> 20 -> 30 -> NULL

    return 0;
}*/
