#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(string word) {
	vector<char> v;
	vector<char> word_v;

	int ch[] = { 'A', 'E', 'I', 'O', 'U' };

	for (int i = 0; i < word.length(); i++) {
		word_v.push_back(word[i]);
	}
	int answer = 0;



	for (int a = 0; a < 5; a++) {
		v.push_back(ch[a]);
		answer++;
		if (v == word_v) return answer;
		for (int b = 0; b < 5; b++) {
			v.push_back(ch[b]);
			answer++;
			if (v == word_v) return answer;
			for (int c = 0; c < 5; c++) {
				v.push_back(ch[c]);
				answer++;
				if (v == word_v) return answer;
				for (int d = 0; d < 5; d++) {
					v.push_back(ch[d]);
					answer++;
					if (v == word_v) return answer;
					for (int e = 0; e < 5; e++) {
						v.push_back(ch[e]);
						answer++;
						if (v == word_v) return answer;
						v.pop_back();
					}
					v.pop_back();
				}
				v.pop_back();
			}
			v.pop_back();
		}
		v.pop_back();

	}

	return answer;
}