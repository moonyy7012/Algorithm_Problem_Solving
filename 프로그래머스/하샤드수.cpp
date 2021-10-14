#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum=0, div=x;
    while(div){
        sum+=div%10;
        div/=10;
    }
    if(!(x%sum)) return true;
    else return false;
}