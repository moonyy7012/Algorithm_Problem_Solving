#include <string>
#include <vector>
#include <iostream>

using namespace std;

pair<string, string> split(string v) {
	pair<string, string> uv;
	int idx = 2, cnt_l = 0, cnt_r = 0;
	//index=2�������� 2�� ������ �÷����鼭 ó������ '('�� ')'�� ������ ���� ������ �Ǵ��Ͽ� ���� 
	for (int i = idx, len = v.length(); i < len + 1; i += 2) {
		cnt_l = 0; cnt_r = 0;
		for (int j = 0; j < i; j++) {
			if (v[j] == '(') cnt_l++;
			else cnt_r++;
		}
		if (cnt_l == cnt_r) { idx = i; break; }
	}
	string s1 = "", s2 = "";
	for (int i = 0; i < idx; i++)
		s1 += v[i];

	for (int i = idx; i < v.length(); i++)
		s2 += v[i];

	uv.first = s1;
	uv.second = s2;
	return uv;
}
bool isCorrect(string u) {
	vector<char> v;
	for (int i = 0, len = u.length(); i < len; i++) {
		if (u[i] == '(') v.push_back('(');
		else {
			if (v.empty()) return false;
			v.pop_back();
		}
	}
	if (v.empty()) return true;
	return false;
}
string reverse(string u) {
	string ret = "";
	for (int i = 1, len = u.length() - 1; i < len; i++) {
		if (u[i] == '(') ret += ')';
		else ret += '(';
	}
	return ret;
}
string recursive(string v) {
	if (v == "") return v;
	pair<string, string> uv = split(v);  //u,v �� ����

//u�� �ùٸ� ��ȣ ���ڿ��̸� ���ڿ� v�� ���� ����Ͽ� 1�ܰ���� ���� �� ����� �ٿ� ��ȯ
	if (isCorrect(uv.first)) {
		string res = uv.first;
		res += recursive(uv.second);
		cout << res << " ";
		return res;
	}
	//u�� �ùٸ� ��ȣ ���ڿ� �ƴ� ���
	else {
		string res = "(";
		res += recursive(uv.second);
		res += ")";
		res += reverse(uv.first);
		cout << res << " ";
		return res;
	}
}

string solution(string p) {
	string answer = "";
	string v = p;
	if (isCorrect(v)) return v;
	answer = recursive(v);


	return answer;
}