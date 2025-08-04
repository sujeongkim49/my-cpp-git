/*#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> firstPattern = { 1, 2, 3, 4, 5 }; //1번 수포자
vector<int> secondPattern = { 2,1, 2, 3, 2, 4, 2, 5 }; //2번 수포자
vector<int> thirdPattern = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }; //3번 수포자
// 각각 반복되는 패턴이므로, 문제 수보다 짧아도 %연산을 통해 순환 가능

vector<int> solution(vector<int> answers) {
	vector<int> answer; //시험 문제의 정답 배열

	vector<int> matchCnt(3); //가장 많이 맞춘 수포자의 번호를 저장

	for (int i = 0; i < answers.size(); i++) {	//모든 문제를 하나씩 확인
		if (answers[i] == firstPattern[i % firstPattern.size()]) {
			matchCnt[0]++;
		}
		if (answers[i] == secondPattern[i % secondPattern.size()]) {
			matchCnt[1]++;
		}
		if (answers[i] == thirdPattern[i % thirdPattern.size()]) {
			matchCnt[2]++;
		}
	}

	int max_score = *max_element(matchCnt.begin(), matchCnt.end()); //max_element() > 범위 내에서 가장 큰 원소의 반복자를 반환
	//*으로 역참조해서 값(맞힌 문제의 최대 개수)를 얻음

	for (int i = 0; i < matchCnt.size(); i++) {
		if (matchCnt[i] == max_score) {
			answer.push_back(i + 1); // 1, 2, 3번 수포자
		}
	}

	return answer;
}*/