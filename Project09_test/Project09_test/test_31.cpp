#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int>amount) {
	//enroll:등록된 판매원의 이름 목록, referral: 각 판매원의 추천인(스폰서), 없으면 "-", seller: 판매한 사람들의 이름 목록, amount: 판매한 물건 수량
	unordered_map<string, string> parent;
	//parent[name] = 추천인 관계를 저장하는 해시맵
	//예: john -> mary

	for (size_t i = 0; i < enroll.size(); ++i) {
		parent[enroll[i]] = referral[i];
	}
	//모든 판매원에 대해 자신의 추천인을 parent에 등록.

	unordered_map<string, int> total;
	for (const auto& name : enroll) {
		total[name] = 0;
	}
	//각 판매원의 수익을 기록할 해시맵 total > 0원 초기화.

	for (size_t i = 0; i < seller.size(); ++i) {
		int money = amount[i] * 100;
		string cur_name = seller[i];
		//cur_name > 현재 판매 중인 판매원의 이름
		
		while (money > 0 && cur_name != "-") {
			int to_distribute = money / 10;
			total[cur_name] += money - to_distribute;
			//판매원은 90만큼 수익을 가져가고 10%를 추천인에게 넘김.

			if (parent.find(cur_name) != parent.end()) {
				cur_name = parent[cur_name]; //추천인이 존재한다면 cur_name을 부모로 갱신 -> 상위 단계로 이동
			}
			else { break; }
			money = to_distribute;
		}
	}

	vector<int> result;
	result.reserve(enroll.size());
	for (const auto& name : enroll) {
		result.push_back(total[name]);
	}

	return result;
}

int main() {
	// 등록된 판매원
	vector<string> enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
	// 추천인 (없으면 "-")
	vector<string> referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };

	// 이번 판매자
	vector<string> seller = { "young", "john", "tod", "emily", "mary" };
	// 판매 개수
	vector<int> amount = { 12, 4, 2, 5, 10 };

	// 솔루션 호출
	vector<int> result = solution(enroll, referral, seller, amount);

	// 출력
	cout << "[최종 수익 결과]\n";
	for (size_t i = 0; i < enroll.size(); ++i) {
		cout << enroll[i] << " : " << result[i] << "\n";
	}

	return 0;
}

//i++의 경우 옛 값의 복사본을 만들고, 그 다음에 증가시키는 동작을 수행, 반면 ++i는 복사 없이 바로 증가 진행
//일반 타입에서는 차이가 없지만, 이터레이터(iterator)같은 복잡한 객체에서는 i++가 불필요한 복사를 만들 수 있기 때문에 습관적으로 ++i를 쓰는 것이 더 좋음.