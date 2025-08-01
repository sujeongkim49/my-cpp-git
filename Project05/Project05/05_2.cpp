#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	sort(arr.rbegin(), arr.rend());
	return arr;
}

vector<int> solution(vector<int> lst) {
	sort(lst.rbegin(), lst.rend());
	lst.erase(unique(lst.begin(), lst.end()), lst.end());
	return lst;
}

bool compare(int a, int b) {
	return a > b;
}

vector<int> solution(vector<int> list) {
	sort(list.begin(), list.end(), compare);
	list.erase(unique(list.begin(), list.end()), list.end());

	return list;
}