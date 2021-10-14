#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int n=-1;
    for(int i=0, len=arr.size(); i<len; i++)
        if(n!=arr[i]) {answer.push_back(arr[i]); n=arr[i];}


    return answer;
}
