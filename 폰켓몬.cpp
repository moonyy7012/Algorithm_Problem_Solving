#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int len=nums.size();
    vector<bool> v(200001,false);
    int cnt=0;
    for(int i=0; i<len; i++)
    {
        if(!v[nums[i]]) {
            v[nums[i]]=true;
            cnt++;
        }
    }

    answer=cnt<(len/2)?cnt:(len/2);

    return answer;
}