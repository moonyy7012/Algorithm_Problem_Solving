#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer;

	for (long long i = left; i <= right; i++) {
		long long mok = i / n, res = i % n;
		long long temp = res <= mok ? mok + 1 : res + 1;
		answer.push_back(temp);
	}

	return answer;
}