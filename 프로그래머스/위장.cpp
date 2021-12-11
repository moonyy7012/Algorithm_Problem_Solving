#include<iostream>
#include<vector>
#include<map>
using namespace std;
int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> m;
	for (int i = 0, len = clothes.size(); i < len; i++)
		m[clothes[i][1]]++;

	for (auto i = m.begin(); i != m.end(); i++)
		answer *= (i->second + 1);

	return answer - 1;
}