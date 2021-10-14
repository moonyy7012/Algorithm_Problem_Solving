#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
vector<string>unit;

//
void extractUnit(string s, vector<char> now, int size, int depth, int idx, vector<bool> isVisited) {
	//s : 개수만큼 부분집합 추출할 메뉴(orders[i]), now : 현재 조합한 상태, size:조합하는 원소개수, depth //: 현재 조합하는 순서, idx : 인덱스 
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
		sort(orders[i].begin(), orders[i].end());  //string도 sort()로 사전순정렬 가능
	}
	return orders;
}

vector<string> solution(vector<string> orders, vector<int> course) {
	orders = sorting(orders);

	vector<string> answer;
	for (int i = 0; i < course.size(); i++) {
		int size = course[i];//메뉴 구성 갯수
		unit = vector<string>();  //메뉴 구성 개수에 따른 부분집합
		map<string, int> m;  //map의 key : 부분집합, value : 횟수
		for (int j = 0, order_n = orders.size(); j < order_n; j++) { //각 사람의 주문내용에서 메뉴 구성갯수만큼 부분집합 뽑아옴  
			vector<char> now;
			vector<bool>isVisited(orders[j].length(), false);
			for (int k = 0, len = orders[j].length(); k < len; k++)
				extractUnit(orders[j], now, size, 1, k, isVisited);

		}

		for (int j = 0, leng = unit.size(); j < leng; j++) { //각 구성의 주문횟수 count
			m[unit[j]]++;
		}
		int maximum = find_max(m);  //주문횟수 중 최대값 
		if (maximum < 2) continue;
		for (auto iter = m.begin(); iter != m.end(); iter++) {  //최댓값을 가진 구성을 찾아 answer에 모두 삽입
			if (iter->second == maximum) answer.push_back(iter->first);
		}
	}

	sort(answer.begin(), answer.end());
	return answer;
}