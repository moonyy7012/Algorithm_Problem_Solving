#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<vector<pair<int, int>>> G;
vector<int> minimum;
int answer = 0;

void dfs(int now, int dist, int K) {
	if (dist > K) return;
	if (dist < minimum[now]) minimum[now] = dist;
	else return;

	for (int i = 0, len = G[now].size(); i < len; i++)
		dfs(G[now][i].first, dist + G[now][i].second, K);

}

int solution(int N, vector<vector<int>> road, int K) {
	G = vector<vector<pair<int, int>>>(N + 1);
	minimum = vector<int>(N + 1, K + 1);

	for (int i = 0, len = road.size(); i < len; i++) {
		int a = road[i][0], b = road[i][1], dis = road[i][2];
		G[a].push_back(make_pair(b, dis));
		G[b].push_back(make_pair(a, dis));
	}
	dfs(1, 0, K);
	for (int i = 1; i < N + 1; i++)
		if (minimum[i] <= K) answer++;

	return answer;
}