#include <string>
#include <map>
#include <iostream>
using namespace std;


int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

map<pair<pair<int, int>, char>, bool> m;


bool check(int i, int j, char dir) {
	int idx = 0;
	if (dir == 'U') {
		idx = 0;
	}
	else if (dir == 'D') {
		idx = 1;
	}
	else if (dir == 'L') {
		idx = 2;
	}
	else if (dir == 'R') {
		idx = 3;
	}


	if (i + dy[idx] >= -5 && i + dy[idx] <= 5 && j + dx[idx] >= -5 && j + dx[idx] <= 5) {
		return true;
	}

	return false;

}


int solution(string dirs) {
	int answer = 0;
	int now_i = 0, now_j = 0;
	for (int i = 0, len = dirs.length(); i < len; i++) {
		if (!check(now_i, now_j, dirs[i])) {
			continue;
		}

		int idx, opp_i, opp_j;
		char opp_dir;
		if (dirs[i] == 'U') {
			idx = 0;
			opp_dir = 'D';
		}
		else if (dirs[i] == 'D') {
			idx = 1;
			opp_dir = 'U';
		}
		else if (dirs[i] == 'L') {
			idx = 2;
			opp_dir = 'R';
		}
		else if (dirs[i] == 'R') {
			idx = 3;
			opp_dir = 'L';
		}

		pair<pair<int, int>, char> temp = make_pair(make_pair(now_i, now_j), dirs[i]);
		pair<pair<int, int>, char> temp2 = make_pair(make_pair(now_i + dy[idx], now_j + dx[idx]), opp_dir);

		if (m.find(temp) == m.end() && m.find(temp2) == m.end()) {
			answer++;
			m[temp] = true;
			m[temp2] = true;
		}

		now_i += dy[idx];
		now_j += dx[idx];
	}

	return answer;
}