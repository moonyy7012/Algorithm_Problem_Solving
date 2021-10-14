#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<bool> isExisted(201, false);
    for(int i=0, len=numbers.size(); i<len-1; i++)
        for(int j=i+1; j<len; j++)
            isExisted[numbers[i]+numbers[j]]=true;

    for(int i=0; i<201; i++)
        if(isExisted[i]) answer.push_back(i);

    return answer;
}