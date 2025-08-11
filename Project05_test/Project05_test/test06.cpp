#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector<int> stageCount(N + 2, 0);
	for (int s : stages) {
		stageCount[s]++;
	}
	//범위 기반 for문을 사용하여 stages 벡터의 각 원소를 순회하면서 stageCount 배열의 해당 인덱스에 1씩 증가시킴

	int totalPlayers = stages.size();
	vector<pair<int, double>> failureRate;

	for (int i = 1; i <= N; i++) {
		if (totalPlayers == 0) {
			failureRate.push_back({ i, 0.0 });
		}
		else {
			double rate = static_cast<double> (stageCount[i]) / totalPlayers;
			failureRate.push_back({ i, rate });
			totalPlayers -= stageCount[i];
		}
	}
	//시간복잡도 O(N + M)

	sort(failureRate.begin(), failureRate.end(), [](auto& a, auto& b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
		});
	//[] > 캡쳐 리스트(여기서는 아무것도 캡쳐하지 않음)
	//(auto &a, auto &b) > 두 개의 매개변수 (a, b)를 참조로 받음. auto를 쓴 이유: 원소의 타입이 pair이라 자동추론
	//a.first: 스테이지 번호(int), a.second: 실패율(double)

	for (auto& p : failureRate) {
		answer.push_back(p.first);
	}
	//p는 failureRate의 각 원소(pair<int, double>)를 참조
	//p.first만 꺼내서 answer에 추가

	return answer;
}*/


/*
vector<double> failureRate(N + 1, 0.0); // 각 스테이지의 실패율을 저장할 벡터

	int totalPlayers = stages.size(); // 전체 플레이어 수

	for (int i = 1; i <= N; i++) {
		int reached = count(stages.begin(), stages.end(), i); // 현재 스테이지에 도달한 플레이어 수
		if (totalPlayers != 0) {
			failureRate[i] = reached / totalPlayers; // 실패율 계산
		}
		else {
			failureRate[i] = 0.0; // 현재 스테이지에 도달한 플레이어가 없으면 실패율은 0
		}
		totalPlayers -= reached; // 현재 스테이지에 도달한 플레이어 수를 전체 플레이어 수에서 빼줌
	}

	sort(failureRate.rbegin(), failureRate.rend());

	for (int i = 1; i <= N; i++) {
		answer.push_back(failureRate[i].first);
	}
*/
//count() 를 이용하면 시간복잡도는 O(N*M)이 되기 때문에 비효율적. > O(N+M)으로 최적화해야 함.