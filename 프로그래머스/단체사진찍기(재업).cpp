#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;
char person[8] = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };
vector<char> order;
map<char, int> idx;
vector<string> data_2;
int cnt;



void check() {
	int n = data_2.size();
	int truecnt = 0;

	for (int i = 0; i < n; i++) {
		int a = -1, b = -1;
		for (int j = 0; j < 8; j++) {
			if (order[j] == data_2[i][0])a = j;
			if (order[j] == data_2[i][2])b = j;
		}

		int dis = abs(a - b) - 1;
		if (data_2[i][3] == '<') {
			if (dis < (int)(data_2[i][4] - '0')) truecnt++;
		}
		else if (data_2[i][3] == '>') {
			if (dis > (int)(data_2[i][4] - '0')) truecnt++;
		}
		else if (data_2[i][3] == '=') {
			if (dis == (int)(data_2[i][4] - '0')) truecnt++;
		}
	}
	if (truecnt == n) {
		cnt++;
	}
	return;

}

void dfs(char p, int depth, vector<bool> visited) {
	order.push_back(p);
	visited[idx[p]] = true;
	if (depth == 8) {
		check();

	}
	else {
		for (int i = 0; i < 8; i++)
			if (!visited[i]) dfs(person[i], depth + 1, visited);
	}
	visited[idx[p]] = false;
	order.pop_back();
	return;
}

int solution(int n, vector<string> data) {
	cnt = 0;
	data_2 = data;

	idx.insert(make_pair('A', 0)); idx.insert(make_pair('C', 1)); idx.insert(make_pair('F', 2));
	idx.insert(make_pair('J', 3)); idx.insert(make_pair('M', 4)); idx.insert(make_pair('N', 5));
	idx.insert(make_pair('R', 6)); idx.insert(make_pair('T', 7));
	for (int i = 0; i < 8; i++) {
		order = vector<char>();
		vector<bool> visited(8, false);
		dfs(person[i], 1, visited);
	}

	return cnt;
}