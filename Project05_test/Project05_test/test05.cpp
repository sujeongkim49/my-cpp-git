/*#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	answer.assign(arr1.size(), vector<int>(arr2[1].size(), 0)); //arr1과 arr2이 행렬 곱을 수행했을 때 최종 행렬의 크기만큼 공간을 할당
	//행렬 곱셈 규칙 : A(m x n) * B(n x p) = C(m x p), 즉, 결과 행의 개수 = arr1의 행 개수 arr1.size(), 결과 열의 개수 = arr2의 열 개수 arr2[0].size() 또는 arr2[1].size()
	//assign() 동작 : answer.assign(행 개수, vector<int>(열 개수, 초기값))
	//answer을 행 개수만큼 만들고, 각 행은 열 개수만큼의 int를 0으로 초기화.
	//행렬 곱 결과의 크기를 미리 알아야, 이중, 삼중 for문에서 인덱스를 안전하게 접근 가능.
	//answer[i][j] +=... 같은 누적 연산을 하려면 처음에 0으로 초기화된 공간이 무조건 필요.
	//push_back()을 반복문 안에서 쓰면 불필요한 메모리 재할당이 발생하고 코드가 복잡해짐.

	for (int i = 0; i < arr1.size(); i++) {
		for (int j = 0; j < arr2[1].size(); j++) {
			for (int k = 0; k < arr2.size(); k++) {
				answer[i][j] += arr1[i][k] * arr2[k][j]; //행렬 곱셈 공식: C[i][j] = A[i][k] * B[k][j]
			}
		}
	}

	return answer;
}*/