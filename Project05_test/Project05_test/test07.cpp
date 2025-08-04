#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool visited[11][11][4];
//false > 아직 (y, x)에서 dir 방향으로 이동한 적이 없음
//true > (y, x)에서 dir 방향으로 이동한 적이 있음
//나중에 같은 길을 다시 가면 visited[y][x][dir] == true가 되어 answer을 늘리지 않음.

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
//배열 좌표계에서는 up > y의 감소

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
		//다음 좌표가 범위를 벗어나면 이번 명령은 무시하고 다음으로 넘어감.

		if (visited[y][x][dir] == false) {
			visited[y][x][dir] = true; //현재 위치에서 dir 방향으로 간 적이 있는지.
			visited[ny][nx][opposite_direction(dir)] = true; //다음 좌표에서 반대 방향으로 돌아온 적이 있는지.
			//이렇게 하면 길을 양쪽 방향에서 모두 방문했다고 표시.
			answer++; //새로운 길 방문.
		}

		x = nx;
		y = ny;
		//위치 갱신
	}

	return answer;
}
