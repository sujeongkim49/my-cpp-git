/*#include <set>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
	set<int> sum; //중복 제거와 자동 오름차순 정렬을 위해 set 사용
	//set은 이진 탐색 트리로 구현 > search, insert, delete 연산이 O(log n) 시간복잡도
	//vector = 동적 배열 > 메모리에 연속된 공간을 사용, 크기가 커지면 새로운 큰 공간을 할당, 기존 데이터를 복사
	// > 자동 정렬, 중복 제거 기능이 없음. 인덱스로 접근이 O(1)이라 빠름
	//set = 메모리에 연속 저장되지 않음. 각 원소가 노드로 존재하며 포인터로 연결되어 있음.
	//> 중복 제거, 자동 정렬 기능이 있음. 인덱스로 접근이 불가능(set[3]같은 건 불가능)함. 시간복잡도는 > O(log n)

	for (size_t i = 0; i < numbers.size(); ++i) {
		for (size_t j = i + 1; j < numbers.size(); ++j) {
			sum.insert(numbers[i] + numbers[j]);
		}
	}

	//sort(sum.begin(), sum.end()); > 이미 set에서 오름차순 정렬이 되어 있음.

	vector<int> answer(sum.begin(), sum.end());
	return answer;
}*/