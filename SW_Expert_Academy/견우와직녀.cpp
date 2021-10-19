#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int G[11][11], minimum[11][11];
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 }; //4����

void dfs(int x, int y, int time, int make) {
	minimum[x][y] = time;  //�ּҰɸ��ð�

	//���������� �����ϸ� ��
	if (x == n - 1 && y == n - 1) {
		return;
	}

	for (int d = 0; d < 4; d++) {  //��鿡 ���� ����(nx, ny : �̵��� ��ġ)
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n)  //������ ũ�� ����� ���
			continue;

		// �̵��� ���� �� && ���� �ּ� �ð��� ������ ���ϰų� �̹� ���� �ּҽð����� �� ª�� ���
		if (G[nx][ny] == 1 && (minimum[nx][ny] == 0 || minimum[nx][ny] > time + 1)) {
			dfs(nx, ny, time + 1, make);  //�̵�
		}
		// �ٸ��������ϴ� �Ͽ�(���� ��ġ�� ���̰� �̵��ϴ� ��ġ�� �����ε� ���� �ٸ��� ������ �ʾҰ� �ּҽð��� ������ ���߰ų� ���� �ð����� �� ª�� ���)
		else if (G[nx][ny] == 0 && make == 0 && G[x][y] == 1 && (minimum[nx][ny] == 0 || minimum[nx][ny] > time + m - (time%m))) {
			dfs(nx, ny, time + m - (time%m), 1);  //�ٸ� ����� make�� 1 ����
		}
		// ���� �ִ� �ٸ� �ǳʴ� ���(���� ��ġ�� ���̰� �̵��ϴ� ��ġ�� ����Ʈ�ٸ��ε� ���� �ּҽð��� ������ ���߰ų� ���� �ð����� �� ª�� ���)
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
		cout << "#" << t << ' ' << minimum[n - 1][n - 1] << '\n';  //������ ���������� �ּ� �ð�

	}

	return 0;
}