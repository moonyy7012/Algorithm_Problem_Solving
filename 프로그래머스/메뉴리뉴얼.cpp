#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
vector<string>unit;

//
void extractUnit(string s, vector<char> now, int size, int depth, int idx, vector<bool> isVisited) {
	//s : ������ŭ �κ����� ������ �޴�(orders[i]), now : ���� ������ ����, size:�����ϴ� ���Ұ���, depth //: ���� �����ϴ� ����, idx : �ε��� 
	if (depth > size) return;
	now.push_back(s[idx]);
	isVisited[idx] = true;
	if (depth == size) {
		string res = "";
		for (int i = 0; i < size; i++)
			res += now[i];

		unit.push_back(res);
		now.pop_back();
		return;
	}
	for (int j = idx + 1, len = s.length(); j < len; j++)
		if (!isVisited[j])extractUnit(s, now, size, depth + 1, j, isVisited);

	now.pop_back();

}

int find_max(map<string, int> m) {
	int maximum = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second > maximum) maximum = iter->second;
	}
	return maximum;
}
vector<string> sorting(vector<string> orders) {
	for (int i = 0, size = orders.size(); i < size; i++) {
		sort(orders[i].begin(), orders[i].end());  //string�� sort()�� ���������� ����
	}
	return orders;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	orders = sorting(orders);

	vector<string> answer;
	for (int i = 0; i < course.size(); i++) {
		int size = course[i];//�޴� ���� ����
		unit = vector<string>();  //�޴� ���� ������ ���� �κ�����
		map<string, int> m;  //map�� key : �κ�����, value : Ƚ��
		for (int j = 0, order_n = orders.size(); j < order_n; j++) { //�� ����� �ֹ����뿡�� �޴� ����������ŭ �κ����� �̾ƿ�  
			vector<char> now;
			vector<bool>isVisited(orders[j].length(), false);
			for (int k = 0, len = orders[j].length(); k < len; k++)
				extractUnit(orders[j], now, size, 1, k, isVisited);

		}

		for (int j = 0, leng = unit.size(); j < leng; j++) { //�� ������ �ֹ�Ƚ�� count
			m[unit[j]]++;
		}
		int maximum = find_max(m);  //�ֹ�Ƚ�� �� �ִ밪 
		if (maximum < 2) continue;
		for (auto iter = m.begin(); iter != m.end(); iter++) {  //�ִ��� ���� ������ ã�� answer�� ��� ����
			if (iter->second == maximum) answer.push_back(iter->first);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}