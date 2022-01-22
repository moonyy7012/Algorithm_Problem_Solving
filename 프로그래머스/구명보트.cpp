#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	deque<int> dq(people.size());
	copy(people.begin(), people.end(), dq.begin());
	sort(dq.begin(), dq.end());
	while (!dq.empty()) {
		if (dq.size() == 1) {
			answer++;
			break;
		}
		if (dq[0] + dq[dq.size() - 1] <= limit) {
			dq.pop_front();
		}
		dq.pop_back();
		answer++;
	}
	return answer;
}