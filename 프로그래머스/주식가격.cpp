#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	for (int i = 0, len = prices.size(); i < len - 1; i++) {
		bool isInserted = false;
		for (int j = i + 1; j < len; j++) {
			if (prices[i] > prices[j]) {
				answer.push_back(j - i);
				isInserted = true;
				break;
			}
		}
		if (!isInserted) {
			answer.push_back(len - 1 - i);
		}
	}
	answer.push_back(0);
	return answer;
}