#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i=0, len=s.length(); i<len; i++){
        if(s[i]>='A' && s[i]<='Z'){
            if(s[i]+(char)n<='Z')answer+=(char)(s[i]+n);
            else answer+=(char)(s[i]+n-'Z'-1+'A');
        }
        else if(s[i]>='a' && s[i]<='z'){
            if(s[i]+(char)n<='z')answer+=(char)(s[i]+n);
            else answer+=(char)(s[i]+n-'z'-1+'a');
        }
        else if(s[i]==' ') answer+=' ';

    }

    return answer;
}