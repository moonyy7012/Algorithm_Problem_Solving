#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int pcnt=0, ycnt=0;
    for(int i=0, len=s.length(); i<len; i++){
        if(s[i]=='p' || s[i]=='P') pcnt++;
        else if(s[i]=='y' || s[i]=='Y') ycnt++;
    }

    if(ycnt==pcnt) return true;
    else return false;
}