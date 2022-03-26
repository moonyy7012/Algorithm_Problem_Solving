#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

pair<pair<int, int>, pair<int, int>> extractMaximum(vector<int> v) { //행의 최댓값, 두번째로 최댓값 반환
	int len = v.size();
	vector<pair<int, int>> p(len, make_pair(0, 0));
	for (int i = 0; i < len; i++) {
		p[i].first = i;
		p[i].second = v[i];
	}

	sort(p.begin(), p.end(), desc);
	return make_pair(p[0], p[1]);
}

int solution(vector<vector<int>> land)
{

	int len = land.size();

	vector<vector<int>> maximum(len, vector<int>(4));
	for (int i = 0; i < 4; i++) {
		maximum[0][i] = land[0][i];
	}
	for (int i = 1; i < len; i++) {
		pair<pair<int, int>, pair<int, int>> max_pair = extractMaximum(maximum[i - 1]);
		for (int j = 0; j < 4; j++) {
			if (max_pair.first.first == j) {
				maximum[i][j] = max_pair.second.second + land[i][j];
				continue;
			}
			maximum[i][j] = max_pair.first.second + land[i][j];
		}
	}



	return *max_element(maximum[len - 1].begin(), maximum[len - 1].end());

}