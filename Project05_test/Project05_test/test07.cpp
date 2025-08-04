#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool visited[11][11][4];
//false > ���� (y, x)���� dir �������� �̵��� ���� ����
//true > (y, x)���� dir �������� �̵��� ���� ����
//���߿� ���� ���� �ٽ� ���� visited[y][x][dir] == true�� �Ǿ� answer�� �ø��� ����.

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
//�迭 ��ǥ�迡���� up > y�� ����

int todir(char dir) {
	int ret;
	if (dir == 'U')
		ret = 0;
	else if (dir == 'R')
		ret = 1;
	else if (dir == 'D')
		ret = 2;
	else
		ret = 3;
	return ret;
}

bool isNotValid(int x, int y) { return x < 0 || y < 0 || x>10 || y > 10; }

int opposite_direction(int dir) { return (dir + 2) % 4; }

int solution(string dirs) {
	int answer = 0;
	int x = 5, y = 5;

	for (auto c : dirs) {
		int dir = todir(c);
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (isNotValid(nx, ny)) {
			continue;
		}
		//���� ��ǥ�� ������ ����� �̹� ����� �����ϰ� �������� �Ѿ.

		if (visited[y][x][dir] == false) {
			visited[y][x][dir] = true; //���� ��ġ���� dir �������� �� ���� �ִ���.
			visited[ny][nx][opposite_direction(dir)] = true; //���� ��ǥ���� �ݴ� �������� ���ƿ� ���� �ִ���.
			//�̷��� �ϸ� ���� ���� ���⿡�� ��� �湮�ߴٰ� ǥ��.
			answer++; //���ο� �� �湮.
		}

		x = nx;
		y = ny;
		//��ġ ����
	}

	return answer;
}
