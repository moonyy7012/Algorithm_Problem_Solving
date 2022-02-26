#include <string>
#include <vector>

using namespace std;

bool isCorrect(vector<int> idx) {
	int firstNullIdx = -1, len = idx.size();
	for (int i = 0; i < len; i++) {
		if (idx[i] == -1) {
			firstNullIdx = i;
			break;
		}
	}
	if (firstNullIdx != -1) {
		for (int i = firstNullIdx + 1; i < len; i++) {
			if (idx[i] != -1) {
				return false;
			}
		}
	}
	int temp = -1;
	for (int i = 0; i < len; i++) {
		if (idx[i] == -1) {
			continue;
		}
		if (idx[i] < temp) {
			return false;
		}
		temp = idx[i];
	}
	return true;
}

int solution(string skill, vector<string> skill_trees) {
	int ans = 0;
	for (int i = 0, len = skill_trees.size(); i < len; i++) {
		string temp = skill_trees[i];
		vector<int> idx;
		for (int j = 0, len2 = skill.length(); j < len2; j++) {
			bool isExisted = false;
			for (int k = 0, len3 = temp.length(); k < len3; k++) {
				if (skill[j] == temp[k]) {
					isExisted = true;
					idx.push_back(k);
					break;
				}
			}
			if (!isExisted) {
				idx.push_back(-1);
			}

		}
		ans += isCorrect(idx) ? 1 : 0;

	}
	return ans;

}