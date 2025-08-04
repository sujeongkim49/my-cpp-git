/*#include <set>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
	set<int> sum; //�ߺ� ���ſ� �ڵ� �������� ������ ���� set ���
	//set�� ���� Ž�� Ʈ���� ���� > search, insert, delete ������ O(log n) �ð����⵵
	//vector = ���� �迭 > �޸𸮿� ���ӵ� ������ ���, ũ�Ⱑ Ŀ���� ���ο� ū ������ �Ҵ�, ���� �����͸� ����
	// > �ڵ� ����, �ߺ� ���� ����� ����. �ε����� ������ O(1)�̶� ����
	//set = �޸𸮿� ���� ������� ����. �� ���Ұ� ���� �����ϸ� �����ͷ� ����Ǿ� ����.
	//> �ߺ� ����, �ڵ� ���� ����� ����. �ε����� ������ �Ұ���(set[3]���� �� �Ұ���)��. �ð����⵵�� > O(log n)

	for (size_t i = 0; i < numbers.size(); ++i) {
		for (size_t j = i + 1; j < numbers.size(); ++j) {
			sum.insert(numbers[i] + numbers[j]);
		}
	}

	//sort(sum.begin(), sum.end()); > �̹� set���� �������� ������ �Ǿ� ����.

	vector<int> answer(sum.begin(), sum.end());
	return answer;
}*/