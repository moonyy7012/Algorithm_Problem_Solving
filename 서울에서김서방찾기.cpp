#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer="김서방은 ";
    int idx=0;
    for(int i=0, len=seoul.size(); i<len; i++){
        if(seoul[i]=="Kim") {idx=i; break;}
    }
    vector<int> v;
    if(idx){
        while(idx) {
            v.push_back(idx%10);
            idx/=10;
        }
    }
    else v.push_back(0);
    for(int i=v.size()-1; i>=0; i--)
        answer+=(char)('0'+v[i]);

    answer+="에 있다";
    return answer;
}