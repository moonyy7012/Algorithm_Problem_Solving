#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    double f=sqrt(n);
    if(f==(int)f)return (long long)(f+1)*(f+1);
    else return -1;
}