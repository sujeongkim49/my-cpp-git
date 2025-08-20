#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> scores;

    // 삽입
    scores["Alice"] = 90;
    scores["Bob"] = 75;
    scores["Charlie"] = 85;

    // 접근
    cout << "Alice: " << scores["Alice"] << endl;   // 90
    cout << "Bob: " << scores["Bob"] << endl;       // 75

    // 존재 여부 확인
    if (scores.find("David") == scores.end()) {
        cout << "David는 없음" << endl;
    }

    // 수정
    scores["Bob"] += 10; // Bob의 점수 85로 변경

    // 순회 (순서는 랜덤)
    for (auto& p : scores) {
        cout << p.first << " -> " << p.second << endl;
    }

    return 0;
}
