#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    string three = "";
    while(n){
        int a = n%3;
        three+=((char)('0'+a));
        n/=3;
    }


    for(int i=three.length()-1, mul=1; i>-1; i--, mul*=3){
        answer+=((int)(three[i]-'0')*mul);
    }

    return answer;
}
