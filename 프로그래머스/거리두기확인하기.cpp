#include <string>
#include <vector>
#include <utility>

using namespace std;
vector<pair<int, int>> findpeople(vector<string> room) {
	vector<pair<int, int>> people;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (room[i][j] == 'P') { people.push_back(make_pair(i, j)); }
	return people;
}

bool if2check(pair<int, int> p1, pair<int, int> p2, vector<string> room) {
	if (p1.first == p2.first || p1.second == p2.second) {
		if (room[(p1.first + p2.first) / 2][(p1.second + p2.second) / 2] == 'X') return true;
		else false;
	}

	if (room[p1.first][p2.second] == 'X' && room[p2.first][p1.second] == 'X') return true;
	else return false;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int t = 0, len = places.size(); t < len; t++) {
		bool isCorrect = true;
		vector<pair<int, int>> people = findpeople(places[t]);
		for (int i = 0, leng = people.size(); i < leng - 1; i++) {
			for (int j = i + 1; j < leng; j++) {
				int dis = abs(people[i].first - people[j].first) + abs(people[i].second - people[j].second);
				if (dis > 2) continue;
				if (dis == 1) { isCorrect = false; break; }
				if (!if2check(people[i], people[j], places[t])) { isCorrect = false; break; }
			}
			if (!isCorrect) break;
		}
		if (isCorrect) answer.push_back(1);
		else answer.push_back(0);

	}


	return answer;
}