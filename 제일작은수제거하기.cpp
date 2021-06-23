#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size()==1) answer.push_back(-1);
    else{
        int minimum=*min_element(arr.begin(), arr.end());
        for(int i=0, len=arr.size(); i<len; i++)
            if(arr[i]!=minimum)answer.push_back(arr[i]);
    }
    return answer;
}