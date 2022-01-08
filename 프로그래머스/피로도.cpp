#include <string>
#include <vector>

using namespace std;
int maximum = 0;

void dfs(vector<vector<int>> dungeons, int now_k, int depth, vector<bool> visited) {
	int len = dungeons.size();
	if (depth == len) {
		maximum = len;
		return;
	}
	if (depth > maximum) {
		maximum = depth;
	}
	for (int i = 0; i < len; i++) {
		if (!visited[i] && dungeons[i][0] <= now_k) {
			visited[i] = true;
			dfs(dungeons, now_k - dungeons[i][1], depth + 1, visited);
			visited[i] = false;
		}
	}

}
int solution(int k, vector<vector<int>> dungeons) {
	vector<bool> visited(dungeons.size());
	dfs(dungeons, k, 0, visited);
	return maximum;
}