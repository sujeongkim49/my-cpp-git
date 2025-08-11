#include <iostream>
using namespace std;

// 1. ��� ����ü ����
struct Node {
    int data;     // �����͸� �����ϴ� ����
    Node* next;   // ���� ��带 ����Ű�� ������
};

// 2. ���Ḯ��Ʈ�� �� �ڿ� �� ��带 �߰��ϴ� �Լ�
void append(Node*& head, int value) {
    // �� ��� ���� ����
    Node* newNode = new Node{ value, NULL };

    // ����Ʈ�� ��������� �� ��尡 ù ��° ��尡 ��
    if (head == NULL) {
        head = newNode;
        return;
    }

    // ������� �ʴٸ� ������ ��带 ã�Ƽ� ����
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // ���������� �̵�
    }
    temp->next = newNode; // ������ ����� next�� �� ��� �ּ� ����
}

// 3. ���Ḯ��Ʈ�� ����ϴ� �Լ�
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) { // NULL�� ���� ������ �ݺ�
        cout << temp->data << " -> ";
        temp = temp->next; // ���� ���� �̵�
    }
    cout << "NULL\n"; // �� ǥ��
}

// 4. main �Լ�
int main() {
    Node* head = NULL; // ó������ �� ����Ʈ

    // ����� �Է� �ޱ�
    cout << "���� 3���� �Է��ϼ���: ";
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        append(head, num); // �Է¹��� ���ڸ� ����Ʈ�� �߰�
    }

    // ���Ḯ��Ʈ ���
    cout << "���Ḯ��Ʈ ���: ";
    printList(head);

    return 0;
}
