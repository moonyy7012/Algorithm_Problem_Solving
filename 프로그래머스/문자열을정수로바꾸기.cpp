#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int idx=0, mul=1;
    if(s[0]=='+' || s[0]=='-') idx=1;
    for(int i=s.length()-1; i>=idx; i--){
        answer+=((int)(s[i]-'0')*mul);
        mul*=10;
    }
    answer=(s[0]=='-'?-answer:answer);

    return answer;
}