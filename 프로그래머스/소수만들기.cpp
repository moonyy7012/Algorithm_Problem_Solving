#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int sum=0;
    for(int i=0, len=nums.size(); i<len-2; i++)
        for(int j=i+1; j<len-1; j++)
            for(int k=j+1; k<len; k++){
                sum=nums[i]+nums[j]+nums[k];
                int cnt=0;
                for(int a=1; a<sum; a++)
                    if(!(sum%a)) cnt++;

                if(cnt==1) answer++;
            }


    return answer;
}