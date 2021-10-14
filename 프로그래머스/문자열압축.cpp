//https://programmers.co.kr/learn/courses/30/lessons/60057
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = 10000;

	int len = s.length();
	int mid = len / 2;
	if (len == 1) return 1;
	for (int u_len = 1; u_len <= mid; u_len++) {
		int comp_len = 0;
		vector<string> unit;
		vector<int> cnt;
		for (int i = 0; i < len; i += u_len) {
			string temp = "";
			for (int j = i; j < i + u_len; j++) {
				if (j >= s.length()) break;
				temp += s[j];
			}
			if (unit.empty()) { unit.push_back(temp); cnt.push_back(1); continue; }
			if (unit[unit.size() - 1] == temp)cnt[cnt.size() - 1]++;
			else {
				unit.push_back(temp);
				cnt.push_back(1);
			}
		}
		for (int i = 0; i < unit.size(); i++) {
			if (1 < cnt[i] && cnt[i] < 10) comp_len += 1;
			else if (10 <= cnt[i] && cnt[i] < 100) comp_len += 2;
			else if (100 <= cnt[i] && cnt[i] < 1000) comp_len += 3;
			else if (cnt[i] == 1000) comp_len += 4;

			comp_len += unit[i].length();
		}
		answer = min(answer, comp_len);
	}
	return answer;
}