#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define vi vector<int>
using namespace std;
vector<vi> v;
int now_i = 0, now_j = 0, now = 1;


int down(int num, int n) {  //�� �������� ����, num:���԰���
	for (int i = 0; i < num; i++) {
		v[now_i++][now_j] = now++;
	}
	now_i--; now_j++;
	return num - 1;
}
int straight(int num, int n) {  //�տ��� �ڷ� �̵��ϸ� ����, num:���԰���
	for (int i = 0; i < num; i++) {
		v[now_i][now_j++] = now++;
	}
	now_j -= 2; now_i--;
	return num - 1;
}

int up(int num, int n) {  //�տ��� �ڷ� �̵��ϸ� ����, num:���԰���
	for (int i = 0; i < num; i++) {
		v[now_i--][now_j--] = now++;
	}
	now_i += 2; now_j++;
	return num - 1;
}


vector<int> solution(int n) {
	vector<int> answer;
	v = vector<vi>(n);
	//�Ƕ�̵� Ʋ ���� �����
	for (int i = 1; i <= n; i++) {
		v[i - 1] = vector<int>(i);
	}
	int num = n;
	while (true) {
		num = down(num, n);
		if (num == 0) break;
		num = straight(num, n);
		if (num == 0) break;
		num = up(num, n);
		if (num == 0) break;

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			answer.push_back(v[i][j]);
		}
	}

	return answer;
}