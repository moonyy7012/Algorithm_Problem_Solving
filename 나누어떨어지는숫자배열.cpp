#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());
    for(int i=0, len=arr.size(); i<len; i++)
        if(!(arr[i]%divisor)) answer.push_back(arr[i]);

    if(answer.empty()) answer.push_back(-1);

    return answer;
}