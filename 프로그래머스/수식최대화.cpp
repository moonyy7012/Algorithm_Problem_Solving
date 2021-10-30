#include<iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

long long calc(deque<long long> num, deque<char> op, vector<char> order) {
	for (int i = 0; i < order.size(); i++) {
		deque <long long> t_num;
		deque <char> t_op;
		t_num.push_back(num.front());
		num.pop_front();

		while (!op.empty()) {
			if (op[0] == order[i]) {
				if (op[0] == '+')t_num.back() += num[0];
				else if (op[0] == '-') t_num.back() -= num[0];
				else if (op[0] == '*') t_num.back() *= num[0];
				num.pop_front();
				op.pop_front();
			}
			else {
				t_num.push_back(num[0]);
				num.pop_front();
				t_op.push_back(op[0]);
				op.pop_front();
			}
		}
		num = t_num;
		op = t_op;
	}
	return num[0];
}


long long solution(string expression) {
	long long answer = 0;
	deque<long long> num;
	deque<char> op;
	long long n = 0;
	for (int i = 0, len = expression.length(); i < len; i++) {
		if (expression[i] >= '0' && expression[i] <= '9') {
			n *= 10;
			n += ((int)(expression[i] - '0'));
		}
		else {
			num.push_back(n);
			n = 0;
			op.push_back(expression[i]);
		}
	}
	num.push_back(n);
	vector<char> order(3, '*');
	order[1] = '+';
	order[2] = '-';
	long long maximum = 0;
	do {
		maximum = max(maximum, abs(calc(num, op, order)));

	} while (next_permutation(order.begin(), order.end()));



	return maximum;
}