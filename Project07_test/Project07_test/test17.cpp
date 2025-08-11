#include <string>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	queue<string> q1, q2;

	for (auto &c : cards1) q1.push(c);
	for (auto &c : cards2) q2.push(c);

	for (auto& g : goal) {
		if (!q1.empty() && q1.front() == g) {
			q1.pop();
		}
		else if (!q2.empty() && q2.front() == g) {
			q2.pop();
		}
		else {
			return "No"; // 현재 목표 카드가 두 큐의 앞에 있는 카드와 일치하지 않으면 "No" 반환
		}
	}

	return "yes"; // 모든 목표 카드를 성공적으로 처리했으면 "Yes" 반환
}


int main() {
	vector<string> c1 = { "i", "drink", "water" };
	vector<string> c2 = { "want", "to"}; 
	vector<string> c3 = { "i", "water", "drink" };
	vector<string> goal1 = { "i", "want", "to", "drink", "water" };

	cout << solution(c1, c2, goal1) << endl;
	cout << solution(c1, c3, goal1) << endl;

	return 0;
}

/*
for (int i = 0; i < goal.size(); i++) {
		if (i % 2 == 0) {
			if (cards1.empty() || cards1.front() != goal[i]) {
				return "No";
			}
			else {
				cards1.pop();
				goal.pop();
			}
		}
		else {
			if (cards2.empty() || cards2.front() != goal[i]) {
				return "No";
			}
			else {
				cards2.pop();
				goal.pop();
			}
		}
	}
	if((cards1.empty() && cards2.empty()) || goal.empty()) {
		return "Yes";
	}
*/