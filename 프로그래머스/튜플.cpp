#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool sorting(pair<int, int> p1, pair<int, int>p2) {
	return (p1.second > p2.second);
}

vector<int> solution(string s) {
	vector<int> answer;
	int num = 0, ctype = 2; //ctype-> 1: 숫자, 2:문자
	map<int, int> m;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ctype = 1;
			num *= 10;
			num += (int)(s[i] - '0');
		}
		else {
			if (ctype == 1) {
				m[num]++;
				num = 0;
				ctype = 2;
			}
		}
	}
	vector<pair<int, int>> cnt;
	pair<int, int> p;
	for (auto i = m.begin(); i != m.end(); i++) {
		cnt.push_back(make_pair(i->first, i->second));
	}

	sort(cnt.begin(), cnt.end(), sorting);
	for (int i = 0; i < cnt.size(); i++)
		answer.push_back(cnt[i].first);

	return answer;
}