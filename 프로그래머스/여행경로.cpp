#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> ans;
void dfs(vector<vector<string>> tickets, int len, vector<string> now, vector<bool> used){
    int now_cnt = now.size();
    if(now_cnt==len+1){
        ans.push_back(now);
        return;
    }
    if(!now_cnt){
        for(int i=0; i<len; i++){
            if(tickets[i][0]=="ICN") {
                now.push_back("ICN");
                now.push_back(tickets[i][1]);
                used[i]=true;
                dfs(tickets, len, now, used);
                now.pop_back();
                now.pop_back();
                used[i]=false;
            }
        }
    }
    else{
        for(int i=0; i<len; i++){
            if(used[i]) continue;
            if(now[now_cnt-1]==tickets[i][0]) {
                now.push_back(tickets[i][1]);
                used[i]=true;
                dfs(tickets, len, now, used);
                now.pop_back();
                used[i]=false;
            }
        }
    }
    return;
}

vector<string> solution(vector<vector<string>> tickets) {
    int len=tickets.size();
    vector<bool> used(len, false);
    vector<string> now;
    dfs(tickets, len, now, used);
    sort(ans.begin(), ans.end());

    return ans[0];
}