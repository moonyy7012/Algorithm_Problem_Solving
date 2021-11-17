#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
set<int> johap;
int answer = 0;

void makeJohap(string now, string numbers, vector<bool> visited) {  //��� �κ����� ã��
	for (int i = 0; i < numbers.length(); i++) {
		if (visited[i]) continue;
		string next = now + numbers[i];
		visited[i] = true;
		johap.insert(stoi(next)); //�ߺ� ���� set�� ����ֱ�
		makeJohap(next, numbers, visited);
		visited[i] = false;
	}


}

//�Ҽ� ã�� ����ġ�� - 2�� �Ҽ�/1���� ����/�����ڸ� 0�� �� ����/2����¦������/3���� �����ٱ����� Ȧ���� ������ ���� �Ͽ� ����������� ���� �ִ��� Ȯ��
void isPrime(int num) { //�ش� ���ڰ� �Ҽ����� �Ǻ�
	if (num == 2) { answer++; return; }
	if (num <= 1 || !(num & 1) || !(num % 2)) return;
	for (int i = 3, last = sqrt(num); i <= last; i += 2) {
		if (!(num%i)) return;
	}
	answer++;
}

int solution(string numbers) {
	vector<bool> visited(numbers.length());
	makeJohap("", numbers, visited);

	for (auto i = johap.begin(); i != johap.end(); i++) { //���� �κ����յ��� ���� �Ҽ����� �Ǻ�
		cout << *i << " ";
		isPrime(*i);
	}


	return answer;
}