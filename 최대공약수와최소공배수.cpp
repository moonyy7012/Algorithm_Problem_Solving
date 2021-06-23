#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int maximum=min(n, m);
    while(maximum>0){
        if(!(n%maximum)&&!(m%maximum)) {
            answer.push_back(maximum);
            break;
        }
        maximum--;
    }
    int bigger=max(n, m), smaller=min(n, m), mul=1;
    while(1){
        if(!(bigger*mul%smaller)) {
            answer.push_back(bigger*mul);
            break;
        }
        mul++;
    }

    return answer;
}