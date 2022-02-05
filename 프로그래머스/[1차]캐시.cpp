#include <string>
#include <deque>
#include <vector>
#include <cctype>
using namespace std;

bool isSame(string a, string b) {
	if (a.length() != b.length()) return false;

	for (int i = 0, len = a.length(); i < len; i++) {
		if (toupper(a[i]) != toupper(b[i])) return false;
	}
	return true;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	deque<string> cache;
	if (cacheSize == 0) {
		return cities.size() * 5;
	}
	cache.push_back(cities[0]);
	answer += 5;
	for (int i = 1, len = cities.size(); i < len; i++) {
		bool isExisted = false;
		for (int j = 0, len2 = cache.size(); j < len2; j++) {
			if (isSame(cache[j], cities[i])) {
				cache.erase(cache.begin() + j);
				cache.push_back(cities[i]);
				isExisted = true;
				answer += 1;
				break;
			}
		}
		if (!isExisted) {
			answer += 5;
			cache.push_back(cities[i]);
			if (cache.size() > cacheSize) {
				cache.pop_front();
			}
		}

	}

	return answer;
}