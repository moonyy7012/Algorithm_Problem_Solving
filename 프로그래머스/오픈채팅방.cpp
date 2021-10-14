//https://programmers.co.kr/learn/courses/30/lessons/42888?language=cpp
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> idname;
	map<string, string>::iterator iter;
	vector<string> ids;
	for (int i = record.size() - 1; i >= 0; i--) {
		int first = 6;
		if (record[i][0] == 'C')first = 7;
		string id = "", name = "", s = "";
		for (int j = first, len = record[i].length(); j < len; j++) {
			if (record[i][j] == ' ') { id = s; s = ""; continue; }
			s += record[i][j];
		}
		name = s;
		if (record[i][0] == 'L') {
			ids.push_back(name);
			continue;
		}
		ids.push_back(id);
		if (idname.find(id) == idname.end()) {
			idname.insert(make_pair(id, name));
		}
	}
	for (int i = 0, len = record.size(); i < len; i++) {
		if (record[i][0] == 'C') continue;
		string s = idname[ids[len - 1 - i]];
		s += "님이 ";
		if (record[i][0] == 'E') {
			s += "들어왔습니다.";
		}
		else if (record[i][0] == 'L') {
			s += "나갔습니다.";
		}
		answer.push_back(s);
	}

	return answer;
}