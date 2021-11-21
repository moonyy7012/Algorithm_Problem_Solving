#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
	int ans = 0, cnt = 0, len = name.length();
	for (int i = 0; i < len; i++) {
		ans += min('Z' - name[i] + 1, name[i] - 'A');
	}

	//앞에서 뒤쪽 한 방향으로 이동할 때 이동해야 하는 거리 구하기
	int dis = -1;
	for (int i = len - 1; i >= 0; i--)
		if (name[i] != 'A') { dis = i; break; }

	if (dis == -1) return ans;

	//모든 경우의 수를 구해 최소 거리 구하기
	for (int i = 0; i < len; i++) {
		if (name[i] != 'A') continue;
		int right = i + 1;
		while (right < len && name[right] == 'A') right++;
		dis = min(dis, (i > 0 ? (i - 1) * 2 : 0) + len - right);
		i = right - 1;
	}
	return ans + dis;
}