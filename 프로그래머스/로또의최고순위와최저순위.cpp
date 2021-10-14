#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt=0;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    int idx=0, corcnt=0, zerolot=0;
    for(int i=0; i<6; i++){
        if(lottos[i]==0) {zerolot++; continue;}
        for(int j=idx; j<6; j++){
            if(lottos[i]==win_nums[j]) {corcnt++; idx=j; break;}
        }
    }

    //최고
    corcnt+zerolot>=2?answer.push_back(7-(corcnt+zerolot)):answer.push_back(6);
    //최저
    corcnt>=2?answer.push_back(7-corcnt):answer.push_back(6);

    return answer;
}