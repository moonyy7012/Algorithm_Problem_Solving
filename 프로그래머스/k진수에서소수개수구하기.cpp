#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

string convertToK(int n, int k) {
	string s = "";
	while (n) {
		s = (char)('0' + n % k) + s;
		n /= k;
	}
	return s;
}

vector<string> divide(string k_digit) {
	vector<string> v;
	string s = "";
	for (int i = 0, len = k_digit.length(); i < len; i++) {
		if (k_digit[i] == '0') {
			if (s != "") {
				v.push_back(s);
			}
			s = "";
		}
		else {
			s += k_digit[i];
		}
	}
	if (s != "") {
		v.push_back(s);
	}
	return v;
}

int isPrime(string s) {
	long long num = stol(s);
	if (num == 1) return 0;
	long long limit = (int)(sqrt(num));
	for (long long i = 2; i <= limit; i++) {
		if (num%i == 0) return 0;
	}
	return 1;
}

int solution(int n, int k) {
	int answer = 0;
	//k진수로 변환
	string k_digit = convertToK(n, k);
	//0으로 나누어 배열 저장
	vector<string> division = divide(k_digit);

	//배열에서 하나씩 꺼내어 소수인지 판단
	for (int i = 0, len = division.size(); i < len; i++) {
		answer += isPrime(division[i]);
	}

	return answer;
}