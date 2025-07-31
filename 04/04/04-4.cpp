#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> vec = { 10,20, 30, 40, 50 };

	//��ȸ�ϰ� ���
	for(auto it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//Ž��
	auto result = find(vec.begin(), vec.end(), 30);
	if(result != vec.end()) {
		cout << "Found: " << *result << endl;
	} else {
		cout << "Not Found: " << endl;
	}

	return 0;
}