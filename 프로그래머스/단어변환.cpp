#include <string>
#include <vector>

using namespace std;
int minimum=55;
void dfs(string now, string target, int n, vector<string> words, int leng, vector<bool> stack){
    if(now==target) {if(minimum>n)minimum=n; return;}
    for(int i=0, len=words.size(); i<len; i++){
        if(stack[i]) continue;
        int cnt=0;
        for(int j=0; j<leng; j++)
            if(now[j]!=words[i][j]) cnt++;

        if(cnt==1) {
            stack[i]=true;
            dfs(words[i], target, n+1, words, leng, stack);
            stack[i]=false;
        }
    }
    return;
}

int solution(string begin, string target, vector<string> words) {

    bool isExist=false;
    for(int i=0, len=words.size(); i<len; i++)
        if(words[i]==target) isExist=true;

    if(!isExist) return 0;

    int length=begin.length();
    vector<bool> stack(words.size(), false);
    dfs(begin, target, 0, words, length, stack);

    return minimum;
}