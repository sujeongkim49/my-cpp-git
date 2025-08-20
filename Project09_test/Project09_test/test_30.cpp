/*#include <iostream>
using namespace std;

int solution(int n, int a, int b) {
	int answer = 0;

	do {
		a = (a + 1) / 2; //참가자 번호를 다음 라운드 번호로 갱신하는 방법
		b = (b + 1) / 2;
		++answer; //한 라운드가 진행되었으니 카운트 증가
	} while (a != b); //a, b가 같은 라운드에서 만남.
	//do while 반복문 > 최소 한 번 실행, 끝에서 조건을 검사해 참이면 다시 반복

	return answer;
}

int main() {
	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	cout << endl;

	int result = solution(n, a, b);

	cout << "참가자" << a << " 참가자" << b << " 는 " << result << "라운드에서 만납니다." << endl;

	return 0;
}*/