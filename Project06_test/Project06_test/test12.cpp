/*#include <vector>
#include <stack>
#include <string>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	//크기가 price.size()인 벡터를 만들고 모든 원소를 기본값(0)으로 초기화한다. > (int의 기본값은 0)
	stack<int> s;

	int priceNum = prices.size();
	//반복문에서 여러 번 prices.size()를 호출하는 것을 방지하기 위해 변수에 저장한다. > 성능 미세 최적화

	for (int i = 0; i < priceNum; i++) {
		while (!s.empty() && prices[s.top()] > prices[i]) {
			answer[s.top()] = i - s.top();
			//보유 기간 = 떨어진 시점 인덱스 - 구매 시점 인덱스
			s.pop();
			//이미 가격이 떨어져 보유 기간을 기록했으므로 스택에서 제거
		}
		s.push(i);
		//현재 가격 인덱스를 스택에 저장
	}

	while (!s.empty()) {
		answer[s.top()] = priceNum - s.top() - 1;
		s.pop();
		//끝까지 가격이 떨어지지 않은 경우, 유지 기간 = 마지막 인덱스 - 구매 시점 인덱스
		//모든 남은 인덱스에 대해 계산 후 스택 비움.
	}
	return answer;
}*/