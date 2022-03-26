#include <string>
#include <vector>

using namespace std;

string toBinary(int n) {
	string s = "";
	while (n) {
		s = (char)('0' + n % 2) + s;
		n /= 2;
	}
	return s;
}
int countOne(string s) {
	int cnt = 0;
	for (int i = 0, len = s.length(); i < len; i++) {
		if (s[i] == '1') {
			cnt++;
		}
	}
	return cnt;
}

int solution(int n) {
	string nBinary = toBinary(n);
	int nCnt = countOne(nBinary);
	n++;
	while (true) {
		if (nCnt == countOne(toBinary(n))) {
			return n;
		}
		n++;
	}

}