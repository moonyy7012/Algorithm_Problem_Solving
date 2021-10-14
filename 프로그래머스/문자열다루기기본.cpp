#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if(s.length()==4 || s.length()==6){
        int len=s.length();
        for(int i=0; i<len; i++)
            if(!(s[i]>='0' && s[i]<='9'))return false;

        return true;
    }
    else return false;

}