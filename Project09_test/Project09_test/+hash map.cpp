#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> scores;

    // ����
    scores["Alice"] = 90;
    scores["Bob"] = 75;
    scores["Charlie"] = 85;

    // ����
    cout << "Alice: " << scores["Alice"] << endl;   // 90
    cout << "Bob: " << scores["Bob"] << endl;       // 75

    // ���� ���� Ȯ��
    if (scores.find("David") == scores.end()) {
        cout << "David�� ����" << endl;
    }

    // ����
    scores["Bob"] += 10; // Bob�� ���� 85�� ����

    // ��ȸ (������ ����)
    for (auto& p : scores) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}
