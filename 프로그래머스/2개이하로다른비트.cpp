#include <string>
#include <vector>
#include <iostream>
using namespace std;
//¦���̸� f(x)=x+1
//Ȧ���̸� x(2����)���� ������ 0�� 1�� �ٲٰ� �� ��ġ �ٷ� ���� 1�� 0���� �ٲ۴�.
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