#include <string>
#include <vector>

using namespace std;

int convCnt = 0, remvCnt = 0;
string toBinary(int len) {
	string s = "";
	while (len) {
		s = to_string(len % 2) + s;
		len /= 2;
	}
	return s;
}

string convert(string s) {
	string temp;
	for (int i = 0, len = s.length(); i < len; i++) {
		if (s[i] == '1') {
			temp += '1';
		}
		else {
			remvCnt++;
		}
	}
	temp = toBinary(temp.length());
	convCnt++;
	return temp;
}


vector<int> solution(string s) {
	vector<int> answer;

	while (s != "1") {
		s = convert(s);
	}

	answer.push_back(convCnt);
	answer.push_back(remvCnt);


	return answer;
}