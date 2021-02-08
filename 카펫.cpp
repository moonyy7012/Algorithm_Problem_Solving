#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool desc(int i, int j){
    return i>=j;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    float limit=sqrt(yellow);
    for(int i=1; i<=limit; i++){

        if(!(yellow%i)) {
            int j=yellow/i;
            if(brown==i*2+j*2+4){
                answer.push_back(i+2);
                answer.push_back(j+2);
                sort(answer.begin(), answer.end(), desc);
                break;
            }
        }
    }
    return answer;
}