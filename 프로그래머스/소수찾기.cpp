#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;
set<int> johap;
int answer = 0;

void makeJohap(string now, string numbers, vector<bool> visited) {  //모든 부분집합 찾기
	for (int i = 0; i < numbers.length(); i++) {
		if (visited[i]) continue;
		string next = now + numbers[i];
		visited[i] = true;
		johap.insert(stoi(next)); //중복 없는 set에 집어넣기
		makeJohap(next, numbers, visited);
		visited[i] = false;
	}


}

//소수 찾는 가지치기 - 2는 소수/1이하 제외/일의자리 0인 수 제외/2외의짝수제외/3부터 제곱근까지의 홀수를 나누는 수로 하여 나누어떨어지는 것이 있는지 확인
void isPrime(int num) { //해당 숫자가 소수인지 판별
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

	for (auto i = johap.begin(); i != johap.end(); i++) { //구한 부분집합들이 각각 소수인지 판별
		cout << *i << " ";
		isPrime(*i);
	}


	return answer;
}