#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;


vector<string> distribute(string s) {
	vector<string> group;
	int n = s.length();
	string head = "", number = "", tail = "";
	int now_idx = 0;

	//head 저장
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			now_idx = i;
			break;
		}
		else {
			head += s[i];
		}
	}

	//number 저장
	for (int i = now_idx; i < now_idx + 5; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (i == now_idx + 4) now_idx = i + 1;
			number += s[i];
		}
		else {
			now_idx = i;
			break;
		}
	}

	//tail 저장
	for (int i = now_idx; i < n; i++) {
		tail += s[i];
	}

	group.push_back(head);
	group.push_back(number);
	group.push_back(tail);

	return group;
}

string toUpper(string s) {
	string ret;
	for (int i = 0; i < s.length(); i++) {
		ret += toupper(s[i]);
	}
	return ret;
}


bool sorting(pair<string, int> a, pair<string, int> b) {
	vector<string> a_group, b_group;
	a_group = distribute(a.first);
	b_group = distribute(b.first);

	if (toUpper(a_group[0]) < toUpper(b_group[0])) {
		return true;
	}
	else if (toUpper(a_group[0]) > toUpper(b_group[0])) {
		return false;
	}
	else {
		if (stoi(a_group[1]) < stoi(b_group[1])) {
			return true;
		}
		else if (stoi(a_group[1]) > stoi(b_group[1])) {
			return false;
		}
		else {
			return a.second < b.second;
		}

	}

}



//그룹 나누기 -> HEAD에서 정렬 -> 같은 것 중에서 NUMBER 정렬 -> 같은 것 중에서 입력 순서대로 
vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<pair<string, int>> temp;  //int는 입력에서의 index값
	for (int i = 0, len = files.size(); i < len; i++) {
		temp.push_back(make_pair(files[i], i));
	}

	sort(temp.begin(), temp.end(), sorting);

	for (int i = 0, len = temp.size(); i < len; i++) {
		answer.push_back(temp[i].first);
	}


	return answer;
}