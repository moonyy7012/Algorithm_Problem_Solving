#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int len = answers.size();
    int a1[5]={1, 2, 3, 4, 5};
    int a2[8]={2, 1, 2, 3, 2, 4, 2, 5};
    int a3[10]={3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<int> v(3, 0);
    for(int i=0; i<len; i++){
        if(a1[i%5]==answers[i]) v[0]++;
    }
    for(int i=0; i<len; i++){
        if(a2[i%8]==answers[i]) v[1]++;
    }
    for(int i=0; i<len; i++){
        if(a3[i%10]==answers[i]) v[2]++;
    }
    int maximum=*max_element(v.begin(), v.end());

    for(int i=0; i<3; i++)
        if(v[i]==maximum) answer.push_back(i+1);


    return answer;
}