#include <string>
#include <vector>

using namespace std;

vector<vector<int>> G;
int one_cnt = 0;
int zero_cnt = 0;


void dfs(int size, int start_i, int start_j) {
	int num = G[start_i][start_j];
	if (size == 1) {
		num == 1 ? (one_cnt += 1) : (zero_cnt += 1);
		return;
	}
	bool isSame = true;
	for (int i = start_i; i < start_i + size; i++) {
		for (int j = start_j; j < start_j + size; j++) {
			if (num != G[i][j]) {
				isSame = false;
				goto lab;
			}
		}
	}
lab:
	if (isSame) {
		num == 1 ? (one_cnt += 1) : (zero_cnt += 1);
		return;
	}
	int newSize = size /= 2;
	dfs(newSize, start_i, start_j);
	dfs(newSize, start_i + newSize, start_j);
	dfs(newSize, start_i, start_j + newSize);
	dfs(newSize, start_i + newSize, start_j + newSize);

}

vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer;
	G = arr;
	dfs(arr.size(), 0, 0);

	answer.push_back(zero_cnt);
	answer.push_back(one_cnt);

	return answer;
}