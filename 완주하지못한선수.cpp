#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for(int i=0, len=participant.size(); i<len; i++){
        if(participant[i]!=completion[i]) {  //c++에서 문자열 비교 ==, != 로 가능
            answer += participant[i];
            break;
        }
    }

    return answer;
}