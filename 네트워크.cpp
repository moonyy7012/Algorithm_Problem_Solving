#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<bool> dfs(int v, vector<bool> isvisited, vector<vector<int>> computers){
    int n = computers.size();
    for(int i=0; i<n; i++){ //0-3-2로 연결되어 있을 경우 v=3에서 2로 연결된 것 확인되려면 0부터 차례대로 확인해야함
        if(computers[v][i]&&!isvisited[i]) {
            isvisited[i]=true;
            isvisited=dfs(i, isvisited, computers);
        }
    }
    return isvisited;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> isvisited(n,false);
    for(int i=0; i<n; i++){
        if(!isvisited[i]){
            isvisited[i]=true;
            answer++;
            isvisited=dfs(i, isvisited, computers);
        }
    }

    return answer;
}