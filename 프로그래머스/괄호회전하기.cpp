#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isRightPairBracket(char open, char close) {
	return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

bool isCanRightBracket(string s) {
	int bracket = 0;
	for (int i = 0, len = s.length(); i < len; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			bracket++;
		}
		else {
			bracket--;
		}
	}
	return bracket == 0;
}
//startIdx�� �������� startIdx~�� ���� -> ó��~startIdx-1 ���� 
bool isRightBracket(string s, int startIdx) {
	int len = s.length();
	stack<char> sta;
	for (int i = startIdx; i < len; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			sta.push(s[i]);
		}
		else {
			if (sta.size() <= 0 || !isRightPairBracket(sta.top(), s[i])) {
				return false;
			}
			else {
				sta.pop();
			}
		}
	}
	for (int i = 0; i < startIdx; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			sta.push(s[i]);
		}
		else {
			if (sta.size() <= 0 || !isRightPairBracket(sta.top(), s[i])) {
				return false;
			}
			else {
				sta.pop();
			}
		}
	}
	return sta.empty();
}

int solution(string s) {
	//���� ��ȣ�� �ݴ� ��ȣ�� ������ �ٸ��� X
	if (!isCanRightBracket(s)) return 0;

	int ans = 0;
	for (int i = 0, len = s.length(); i < len; i++) {
		if (isRightBracket(s, i)) {
			ans++;
		}
	}

	return ans;
}