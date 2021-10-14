#include <iostream>
#include<string>
#include<vector>
using namespace std;
// 이렇게 짝 지어 없애는 문제는 STACK 이용!!!

int solution(string s)
{
    int answer = -1;
    vector<int> v;
    v.push_back(s[0]);
    for(int i=1, len=s.length(); i<len; i++){
        v.push_back(s[i]);
        int vlen=v.size();
        if(v[vlen-2]==v[vlen-1]) {v.pop_back(); v.pop_back();}
    }
    if(v.empty()) return 1;
    else return 0;

    return answer;
}