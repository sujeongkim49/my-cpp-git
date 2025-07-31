#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> vec = { 10,20, 30, 40, 50 };

	//순회하고 출력
	for(auto it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	//탐색
	auto result = find(vec.begin(), vec.end(), 30);
	if(result != vec.end()) {
		cout << "Found: " << *result << endl;
	} else {
		cout << "Not Found: " << endl;
	}

	return 0;
}