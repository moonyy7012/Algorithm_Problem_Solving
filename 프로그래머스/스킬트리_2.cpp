#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	for (int i = 0; i < skill_trees.size(); i++) {
		vector<int> v(skill.length(), 30);
		for (int j = 0; j < skill.length(); j++) {
			for (int k = 0; k < skill_trees[i].length(); k++) {
				if (skill[j] == skill_trees[i][k]) v[j] = k;
			}
		}
		bool ok = true;
		for (int l = 0; l < v.size() - 1; l++)
			if (v[l] > v[l + 1]) ok = false;

		if (ok) answer++;
	}
	return answer;
}

