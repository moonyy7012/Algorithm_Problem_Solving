#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool even=true;
    for(int i=0, len=s.length(); i<len; i++){
        if(s[i]==' '){answer+=' '; even=true; continue;}
        if(even){
            if(s[i]>='a' && s[i]<='z'){answer+=(s[i]-'a'+'A');}
            else answer+=s[i];
        }
        else{
            if(s[i]>='A' && s[i]<='Z'){answer+=(s[i]-'A'+'a');}
            else answer+=s[i];
        }
        even=!even;
    }

    return answer;
}