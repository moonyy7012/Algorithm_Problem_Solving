#include <string>
#include <vector>
#include <iostream>
using namespace std;
//짝수이면 f(x)=x+1
//홀수이면 x(2진수)에서 마지막 0을 1로 바꾸고 그 위치 바로 뒤의 1은 0으로 바꾼다.
string toBinaryString(long long num) {
	string ret = "";
	while (num) {
		ret = (char)('0' + num % 2) + ret;
		num /= 2;
	}
	return ret;
}
long long findLastZero(string s) {
	long long idx = -1;
	for (long long i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '0') {
			idx = i;
			break;
		}
	}
	return idx;
}
long long convertToLong(string s) {
	long long ret = 0, num = 1;
	for (long long i = s.length() - 1; i >= 0; i--) {
		ret += (int)(s[i] - '0')*num;
		num *= 2;
	}
	return ret;
}
vector<long long> solution(vector<long long> numbers) {
	vector<long long> answer;
	for (int i = 0, len = numbers.size(); i < len; i++) {
		long long num = numbers[i];
		if (num % 2 == 0) {
			answer.push_back(num + 1);
		}
		else {
			string s = toBinaryString(num);
			long long zero_i = findLastZero(s);
			if (zero_i == -1) {
				s[0] = '0';
				s = '1' + s;
			}
			else {
				s[zero_i] = '1';
				s[zero_i + 1] = '0';
			}
			answer.push_back(convertToLong(s));

		}


	}

	return answer;
}