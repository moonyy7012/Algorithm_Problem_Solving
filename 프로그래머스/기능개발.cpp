#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int len = speeds.size();
	for (int i = 0; i < len; i++) {
		int res = 100 - progresses[i];
		speeds[i] = res % speeds[i] ? res / speeds[i] + 1 : res / speeds[i];
	}

	int high = speeds[0], sum = 1;
	for (int i = 1; i < len; i++) {
		if (speeds[i] > high) { answer.push_back(sum); high = speeds[i]; sum = 1; }
		else sum++;

		if (i == len - 1) answer.push_back(sum);

	}
	return answer;
}
