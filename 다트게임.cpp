#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int i=0, pre=0,sum=0, len=dartResult.length();
    while(i<len){
        int num=0;
        int d = (int)(dartResult[i]-'0');
        if(dartResult[i+1]=='0') {
            i++;
            d=10;
        }
        if(dartResult[i+1]=='S')num=d;
        else if(dartResult[i+1]=='D')num=d*d;
        else if(dartResult[i+1]=='T')num=d*d*d;

        if('0'<=dartResult[i+2] && dartResult[i+2]<='9') {sum+=pre; pre=num; i+=2;}
        else{
            if(dartResult[i+2]=='*') { sum+=(pre*2); pre=num*2;}
            else if(dartResult[i+2]=='#'){sum+=pre; pre=(-num);}
            else{sum+=pre; pre=num;}
            i+=3;
        }
        cout<<sum<<" ";
    }

    sum+=pre;

    return sum;
}