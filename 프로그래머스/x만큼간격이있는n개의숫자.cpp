#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int mul=1;
    while(mul<=n){
        answer.push_back(x*mul);
        mul++;
    }
    return answer;
}
