//https://www.acmicpc.net/problem/1012
#include<iostream>
#include<vector>
using namespace std;
int ans;
int dy[4] = {0,0,1,-1};
int dx[4] = {1, -1, 0, 0};
bool check(int i, int j, int n, int m) {
	if (i >= 0 && i < n && j >= 0 && j < m) return true;
	return false;
}
vector<vector<bool>> dfs(int i, int j, vector<vector<bool>> G, vector<vector<bool>> visited, int depth) {
	if (!G[i][j] || visited[i][j]) return visited;
	visited[i][j] = true;
	if (depth == 1) ans++;
	
	for (int idx = 0; idx < 4; idx++)
		if(check(i + dy[idx], j + dx[idx], G.size(), G[0].size()))visited=dfs(i + dy[idx], j + dx[idx],G,visited,depth+1);

	return visited;
	
}



int main(){
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int m, n, num;
		ans = 0;
		cin >> m >> n >> num;
		vector<vector<bool>> G(n, vector<bool>(m, false));
		vector<vector<bool>> visited(n, vector<bool>(m, false));
		int y, x;
		for (int i = 0; i < num; i++) {
			cin >> x >> y;
			G[y][x] = true;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				visited=dfs(i, j, G,visited, 1);

		cout << ans << "\n";
	}
}