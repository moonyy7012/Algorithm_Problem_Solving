#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> findset(string s) {
	map<string, int> set;
	for (int i = 0, len = s.length(); i < len - 1; i++) {
		string unit = "";
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = (s[i] - 'A' + 'a');
		}
		if (s[i] >= 'a' && s[i] <= 'z') {
			unit += s[i];
		}
		else {
			continue;
		}

		if (s[i + 1] >= 'A' && s[i + 1] <= 'Z') {
			s[i + 1] = (s[i + 1] - 'A' + 'a');
		}
		if (s[i + 1] >= 'a' && s[i + 1] <= 'z') {
			unit += s[i + 1];
			if (set.find(unit) != set.end()) { set[unit] += 1; }
			else { set[unit] = 1; }

		}

	}
	return set;
}

int findintersect(map<string, int> set1, map<string, int> set2) {
	int cnt = 0;
	for (auto iter = set1.begin(); iter != set1.end(); iter++) {
		if (set2.find(iter->first) != set2.end()) {
			cnt += min(iter->second, set2[iter->first]);
		}
	}
	return cnt;
}
int findsum(map<string, int> set1, map<string, int> set2) {
	int cnt = 0;
	for (auto iter = set1.begin(); iter != set1.end(); iter++) {
		if (set2.find(iter->first) != set2.end()) {
			cnt += max(iter->second, set2[iter->first]);
		}
		else {
			cnt += iter->second;
		}
	}
	for (auto iter = set2.begin(); iter != set2.end(); iter++) {
		if (set1.find(iter->first) == set1.end()) {
			cnt += iter->second;
		}
	}
	return cnt;
}
int solution(string str1, string str2) {
	int answer = 0;
	map<string, int> set1, set2;
	set1 = findset(str1);
	set2 = findset(str2);

	if (set1.empty() && set2.empty()) {
		return 65536;
	}

	int intersect = findintersect(set1, set2);
	int sum = findsum(set1, set2);
	answer = (int)((float)intersect / (float)sum * 65536);
	return answer;
}