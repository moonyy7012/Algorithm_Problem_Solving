#include <string>
#include <vector>

using namespace std;


string convertToN(int n, int num) {  //n:진법, num:10진수 숫자
	string s = "";
	if (num == 0) {
		return "0";
	}
	while (num) {
		int temp = num % n;
		if (temp < 10) {
			s = (char)('0' + temp) + s;
		}
		else {
			s = (char)('A' + temp - 10) + s;
		}
		num /= n;
	}
	return s;
}

string findAll(int n, int max_len) {
	string s = "";
	int num = 0;
	while (s.length() <= max_len) {
		s += convertToN(n, num);
		num++;
	}
	return s;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string all = findAll(n, m*t);

	for (int i = p - 1; answer.length() < t; i += m) {
		answer += all[i];
	}


	return answer;
}