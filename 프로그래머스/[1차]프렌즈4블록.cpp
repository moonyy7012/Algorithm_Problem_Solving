#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> board;
int row;
int col;
int cnt_4blocks() { //2X2로 이뤄진 지울 블록 개수 세기
	int cnt = 0;
	vector<vector<bool>> visited(row, vector<bool>(col));
	for (int i = 0; i < row - 1; i++) {
		for (int j = 0; j < col - 1; j++) {
			if (board[i][j] != '.' && board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1]) {
				for (int y = 0; y < 2; y++) {
					for (int x = 0; x < 2; x++) {
						if (!visited[i + y][j + x]) {
							cnt++;
							visited[i + y][j + x] = true;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (visited[i][j]) board[i][j] = '.';
		}
	}

	return cnt;
}
void descending() {
	for (int j = 0; j < col; j++) {
		int desc_idx = row - 2;
		for (int i = row - 1; i > 0; i--) {
			if (board[i][j] == '.') {
				if (desc_idx >= i) desc_idx = i - 1;
				while (desc_idx >= 0 && board[desc_idx][j] == '.') {
					desc_idx--;
				}
				if (desc_idx >= 0) {
					board[i][j] = board[desc_idx][j];
					board[desc_idx][j] = '.';
					desc_idx--;
				}
				else {
					break;
				}
			}
		}
	}

}

int solution(int m, int n, vector<string> map) {
	int answer = 0;
	board = map;
	row = board.size();
	col = board[0].length();
	while (true) {
		int cnt = cnt_4blocks();
		if (cnt == 0)break;
		answer += cnt;
		descending();

	}



	return answer;
}