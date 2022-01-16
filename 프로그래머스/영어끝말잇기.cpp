#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool same(vector<string> words, int idx) {
	for (int i = 0; i < idx; i++) {
		if (words[i] == words[idx]) {
			return true;
		}
	}
	return false;
}
vector<int> solution(int n, vector<string> words) {
	vector<int> answer(2, 0);
	int idx = -1;
	for (int i = 1, len = words.size(); i < len; i++) {
		if (same(words, i)) {
			idx = i;
			break;
		}
		if (words[i][0] != words[i - 1][words[i - 1].length() - 1]) {
			idx = i;
			break;
		}
	}
	if (idx == -1) {
		return answer;
	}
	answer[0] = idx % n + 1;
	answer[1] = idx / n + 1;

	return answer;
}