#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int G[11][11], minimum[11][11];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 }; //4방향

void dfs(int x, int y, int time, int make) {
	minimum[x][y] = time;  //최소걸린시간

	//마지막지점 도달하면 끝
	if (x == n - 1 && y == n - 1) {
		return;
	}

	for (int d = 0; d < 4; d++) {  //사면에 대해 조사(nx, ny : 이동할 위치)
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)  //지도의 크기 벗어나는 경우
			continue;

		// 이동할 곳이 길 && 아직 최소 시간을 구하지 못하거나 이미 구한 최소시간보다 더 짧을 경우
		if (G[nx][ny] == 1 && (minimum[nx][ny] == 0 || minimum[nx][ny] > time + 1)) {
			dfs(nx, ny, time + 1, make);  //이동
		}
		// 다리만들어야하는 겅우(현재 위치는 길이고 이동하는 위치는 절벽인데 아직 다리를 만들지 않았고 최소시간을 구하지 못했거나 구한 시간보다 더 짧을 경우)
		else if (G[nx][ny] == 0 && make == 0 && G[x][y] == 1 && (minimum[nx][ny] == 0 || minimum[nx][ny] > time + m - (time%m))) {
			dfs(nx, ny, time + m - (time%m), 1);  //다리 만들며 make에 1 전달
		}
		// 원래 있던 다리 건너는 경우(현재 위치는 길이고 이동하는 위치는 디폴트다리인데 아직 최소시간을 구하지 못했거나 구한 시간보다 더 짧을 경우)
		else if (G[nx][ny] > 1 && G[x][y] == 1 && (minimum[nx][ny] == 0 || minimum[nx][ny] > time + G[nx][ny] - (time%G[nx][ny]))) {
			dfs(nx, ny, time + G[nx][ny] - (time%G[nx][ny]), make);
		}
	}
}

int main() {
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		memset(G, 0, sizeof(int) * 11 * 11);
		memset(minimum, 0, sizeof(int) * 11 * 11);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> G[i][j];
			}
		}

		dfs(0, 0, 0, 0);
		cout << "#" << t << ' ' << minimum[n - 1][n - 1] << '\n';  //마지막 지점에서의 최소 시간

	}

	return 0;
}