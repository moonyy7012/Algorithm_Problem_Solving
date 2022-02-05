#include <string>
#include <vector>
#include <cmath>
using namespace std;


int cnt = 0;
void dfs(int n, int now, vector<vector<bool>> G) { //n:��ü ����, now:���� ����ž ��ȣ
	cnt++;
	if (cnt == n - 1) { //�� �������� ���
		return;
	}
	for (int i = 1; i < n + 1; i++) {
		if (G[now][i]) {  //i�� ����Ǿ��ִٸ�
			G[now][i] = false;
			G[i][now] = false;
			dfs(n, i, G);
		}
	}
	return;

}

int solution(int n, vector<vector<int>> wires) {
	int answer = 100;

	// G[a][b] �� true�̸� a����ž�� b����ž�� ����Ǿ�����
	vector<vector<bool>> G = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));

	//G�� ����� �ִ� �͵� ���ʷ� ����ֱ�
	for (int i = 0, len = wires.size(); i < len; i++) {
		G[wires[i][0]][wires[i][1]] = true;
		G[wires[i][1]][wires[i][0]] = true;
	}


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (G[i][j]) {//i�� j�� ����Ǿ��ִٸ� 
	//�� ������ �߶��� �� ������ ���¸��� ���� ����ž�� ���� ���ؼ� �� ���� ���� �ּڰ����� ������� answer�� ���� 
				G[i][j] = false;
				G[j][i] = false;
				int a = 0, b = 0;
				cnt = 0;
				dfs(n, i, G);
				a = cnt;
				cnt = 0;
				dfs(n, j, G);
				b = cnt;
				answer = min(answer, abs(a - b));
				G[i][j] = true;
				G[j][i] = true;
			}
		}
	}


	return answer;
}