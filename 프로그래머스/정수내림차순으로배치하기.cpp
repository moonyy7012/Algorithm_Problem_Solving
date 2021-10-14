#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    sort(v.begin(), v.end());
    long long mul=1;
    for(int i=0, len=v.size(); i<len; i++){
        answer+=v[i]*mul;
        mul*=10;
    }

    return answer;
}