#include <string>
#include <vector>
#include <cmath>
using namespace std;


int cnt = 0;
void dfs(int n, int now, vector<vector<bool>> G) { //n:전체 개수, now:현재 송전탑 번호
	cnt++;
	if (cnt == n - 1) { //다 도달했을 경우
		return;
	}
	for (int i = 1; i < n + 1; i++) {
		if (G[now][i]) {  //i와 연결되어있다면
			G[now][i] = false;
			G[i][now] = false;
			dfs(n, i, G);
		}
	}
	return;

}

int solution(int n, vector<vector<int>> wires) {
	int answer = 100;

	// G[a][b] 이 true이면 a송전탑과 b송전탑이 연결되어있음
	vector<vector<bool>> G = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));

	//G에 연결되 있는 것들 차례로 집어넣기
	for (int i = 0, len = wires.size(); i < len; i++) {
		G[wires[i][0]][wires[i][1]] = true;
		G[wires[i][1]][wires[i][0]] = true;
	}


	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (G[i][j]) {//i와 j가 연결되어있다면 
	//그 간선을 잘랐을 때 각각의 전력망이 갖는 송전탑의 개수 구해서 그 차가 현재 최솟값보다 작을경우 answer에 갱신 
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