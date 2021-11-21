#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
vector<vector<int>> M;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


bool check(int y, int x) {
	return (y >= 0 && y < M.size() && x >= 0 && x < M[0].size()) ? true : false;
}


int solution(vector<vector<int>> maps)
{
	int answer = -1;
	M = maps;
	queue<pair<int, int>> q;
	int y_len = maps.size();
	int x_len = maps[0].size();
	vector<vector<int>> dis = vector<vector<int>>(y_len, vector<int>(x_len, 0));
	q.push(make_pair(0, 0));
	dis[0][0] = 1;
	while (!q.empty()) {
		auto point = q.front();
		q.pop();
		if (point.first == y_len - 1 && point.second == x_len - 1) { answer = dis[y_len - 1][x_len - 1]; break; }

		for (int i = 0; i < 4; i++) {
			if (check(point.first + dy[i], point.second + dx[i])) {
				if (maps[point.first + dy[i]][point.second + dx[i]] == 1 && dis[point.first + dy[i]][point.second + dx[i]] == 0)
					q.push(make_pair(point.first + dy[i], point.second + dx[i]));
				dis[point.first + dy[i]][point.second + dx[i]] = dis[point.first][point.second] + 1;

			}
		}
	}


	return answer;
}