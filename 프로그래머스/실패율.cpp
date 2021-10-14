#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <utility>

using namespace std;

bool sorting(pair<int, double> a, pair<int, double> b){
    if(a.second>b.second) return true;
    else if(a.second==b.second) {
        if(a.first>b.first) return false;
        else return true;
    }
    else return false;
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> cnt(N+2,0);
    vector<double> perc(N+1, 0);
    vector<int> answer;
    int len = stages.size();

    for(int i=0; i<len; i++)
        cnt[stages[i]]++;

    int Allcnt=cnt[N+1];
    for(int i=N; i>0; i--){
        Allcnt+=cnt[i];
//         절대 분모에는 0이 들어갈 수 없게 처리!!!
        if(!Allcnt) perc[i]=0;
        else perc[i]=(double)cnt[i]/(double)Allcnt;
    }

//     perc의 index는 stage 번호, perc[idx]값은 해당 stage의 실패율
//     map<key, value>를 이용해서 key에 실패율을 넣어 사용X.
//     key는 유일한 값이어야 하므로 실패율이 같은 값을 삽입하면 중복되어 하나만 남기때문 
//     대신 pair를 사용. pair쌍 여러 개 삽입하려면 벡터 사용.
    for(int i=1; i<=N; i++)
        cout<<perc[i]<<"\n";

    vector<pair<int, double>> res;
    for(int i=1; i<=N; i++)
        res.push_back(make_pair(i, perc[i]));

    sort(res.begin(), res.end(), sorting);
    for(int i=0; i<N; i++)
        answer.push_back(res[i].first);


    return answer;
}