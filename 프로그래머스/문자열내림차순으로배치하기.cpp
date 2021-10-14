#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string s) {
    string answer="";
    vector<int> v(52,0);
    for(int i=0, len=s.length(); i<len; i++){
        if(s[i]>='a') v[(int)(s[i]-'a'+26)]++;
        else v[(int)(s[i]-'A')]++;
    }
    for(int i=51; i>=26; i--){
        for(int j=0; j<v[i]; j++)
            answer+=(char)('a'+i-26);
    }
    for(int i=25; i>=0; i--){
        for(int j=0; j<v[i]; j++)
            answer+=(char)('A'+i);
    }

    return answer;
}