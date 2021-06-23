#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<vector<int>> cnt(26);
    int maximum='a';
    for(int i=0, len=strings.size(); i<len; i++)
        cnt[(int)(strings[i][n]-'a')].push_back(i);

    for(int i=0; i<26; i++){
        if(!(cnt[i].empty())){
            vector<string> choose;
            for(int j=0, len=cnt[i].size(); j<len; j++)
                choose.push_back(strings[cnt[i][j]]);

            sort(choose.begin(), choose.end());
            for(int k=0, len2=choose.size(); k<len2; k++)
                answer.push_back(choose[k]);
        }
    }

    return answer;
}