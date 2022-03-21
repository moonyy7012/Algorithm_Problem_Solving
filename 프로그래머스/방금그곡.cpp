#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// A# : H ~
map<char, char> mp;


class Music {
public:
	string melody;
	int idx;
	int t;

	Music(string a, int b, int c) {
		this->melody = a;
		this->idx = b;
		this->t = c;
	}
};


bool isSame(string melody, string m, int time) {
	int len_melody = melody.length();
	int cnt = time / len_melody;
	int res = time % len_melody;
	string allMelody = "";
	for (int i = 0; i < cnt; i++) {
		allMelody += melody;
	}
	for (int i = 0; i < res; i++) {
		allMelody += melody[i];
	}

	return (allMelody.find(m) != string::npos);

}


string extractMelody(string musicinfo) {
	string ans = "";

	int idx = 0;
	for (int i = musicinfo.length() - 1; i >= 0; i--) {
		if (musicinfo[i] == ',') {
			idx = i;
			break;
		}
	}
	for (int i = idx + 1, len = musicinfo.length(); i < len; i++) {
		ans += musicinfo[i];

	}
	return ans;
}

int calcTime(string musicinfo) {
	int start_time = 0, end_time = 0;
	string start_h = "", start_min = "", end_h = "", end_min = "";
	start_h += musicinfo[0];
	start_h += musicinfo[1];
	start_min += musicinfo[3];
	start_min += musicinfo[4];
	start_time = stoi(start_h) * 60 + stoi(start_min);

	end_h += musicinfo[6];
	end_h += musicinfo[7];
	end_min += musicinfo[9];
	end_min += musicinfo[10];
	end_time = stoi(end_h) * 60 + stoi(end_min);

	return end_time - start_time;
}

vector<Music> findCandidates(string m, vector<string> musicinfos) {
	vector<Music> ans;
	for (int i = 0, len = musicinfos.size(); i < len; i++) {
		string melody = extractMelody(musicinfos[i]);
		int time = calcTime(musicinfos[i]);
		if (isSame(melody, m, time)) {
			ans.push_back(Music(melody, i, time));
		}
	}
	return ans;
}

bool sorting(Music a, Music b) {
	if (a.t > b.t) {
		return true;
	}
	else if (a.t < b.t) {
		return false;
	}
	else {
		return a.idx < b.idx;
	}
}

vector<string> convertSharp(vector<string> musicinfos) {
	vector<string> ans;
	for (int i = 0, len = musicinfos.size(); i < len; i++) {
		string s = "";
		for (int j = 0, len2 = musicinfos[i].length(); j < len2; j++) {
			if (j < len2 - 1 && musicinfos[i][j + 1] == '#') {
				s += mp[musicinfos[i][j]];
				j++;
				continue;
			}
			s += musicinfos[i][j];
		}
		ans.push_back(s);
	}
	return ans;
}

string solution(string m, vector<string> musics) {
	string answer = "";
	mp['A'] = 'H';
	mp['C'] = 'I';
	mp['D'] = 'J';
	mp['F'] = 'K';
	mp['G'] = 'L';

	//#붙은 것 변환
	vector<string> musicinfos = convertSharp(musics);

	string m2 = "";
	for (int i = 0, len = m.length(); i < len; i++) {
		if (i < len - 1 && m[i + 1] == '#') {
			m2 += mp[m[i]];
			i++;
			continue;
		}
		m2 += m[i];
	}

	//조건에 맞는 음악 후보 찾기
	vector<Music> candidates = findCandidates(m2, musicinfos);

	if (candidates.empty()) {
		return "(None)";
	}

	sort(candidates.begin(), candidates.end(), sorting);

	string target = musicinfos[candidates[0].idx];

	for (int i = 12; target[i] != ','; i++) {
		answer += target[i];
	}

	return answer;
}