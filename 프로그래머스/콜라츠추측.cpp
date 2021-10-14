#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    long long num=(long long)n;
    while(num!=1){
        if(answer>=500) return -1;

        if(!(num%2)) num/=2;
        else num=num*3+1;

        answer++;
    }
    return answer;
}