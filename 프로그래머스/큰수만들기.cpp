#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int len = number.length();
	int maxidx = 0;
	for (int i = 0; i < len - k; i++) {
		char maximum = number[maxidx];
		int j = maxidx + 1;
		while (j < len &&  j < k + i + 1) {
			if (maximum < number[j]) {
				maximum = number[j];
				maxidx = j;
			}
			j++;
		}
		answer += maximum;
		maxidx++;
	}


	return answer;
}