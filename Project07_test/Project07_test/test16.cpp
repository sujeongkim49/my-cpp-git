/*#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

//progresses: 각 작업의 현재 진행률, speeds: 각 작업의 하루 작업 속도
//이 두 벡터를 받아서 배포 묶음별 개수를 담은 vector<int>를 반환
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int n = progresses.size(); //총 작업의 개수
	vector<int> days_left(n); //각 작업이 완료되기까지 남은 일수, days_left[0] > 첫 번째 작업의 남은 일수

	for (int i = 0; i < n; ++i) {
		days_left[i] = ceil((100.0 - progresses[i]) / speeds[i]);
		//ceil > 정수 나눗셈에서 올림을 적용
		//(남은 작업량 + 속도 -1) / 속도
	}

	int count = 0; //현재 배포 묶음에 포함된 작업 개수
	int max_day = days_left[0]; //현재 배포 묶음에서 가장 오래 걸리는 작업의 완료일(배포 기준일) > 첫 번째 작업부터 시작하므로 초기값은 days_left[0]

	for (int i = 0; i < n; ++i) {
		if (days_left[i] <= max_day) { //현재 작업이 배포 기준일보다 빨리 또는 동시에 끝난다면
			count++; //같은 배포 묶음에 포함
		}
		else { //현재 작업이 배포 기준일보다 늦게 끝난다면
			answer.push_back(count); //이전 배포 묶음의 작업 개수를 저장
			count = 1; //새로운 묶음을 시작하므로 개수 초기화
			max_day = days_left[i]; //새 배포 묶음의 기준일을 현재 작업 완료일로 변경
		}
	}

	answer.push_back(count);
	return answer;
}*/