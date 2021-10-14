#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;


void dfs(vector<char> v, int depth, vector<string> data, vector<char> friends1, vector<bool> Exist){
    if(depth!=8) {
        for(int i=0; i<8; i++){
            if(!(Exist[i])){
                v.push_back(friends1[i]);
                Exist[i]=true;
                dfs(v, depth+1, data, friends1, Exist);
                v.pop_back();
                Exist[i]=false;
            }
        }
    }
    else{

        int len=data.size();
        bool isCorrect=true;
        for(int i=0; i<len; i++){
            int idxa, idxb;
            for(int j=0; j<8; j++){
                if(v[j]==data[i][0]) idxa=j;
                if(v[j]==data[i][2]) idxb=j;
            }
            if(data[i][3]=='='){
                if(abs(idxa-idxb)!=(int)(data[i][4]+1-'0')) {isCorrect=false; break;}
            }
            else if(data[i][3]=='<'){
                if(abs(idxa-idxb)>=(int)(data[i][4]+1-'0')) {isCorrect=false; break;}
            }
            else if(data[i][3]=='>'){
                if(abs(idxa-idxb)<=(int)(data[i][4]+1-'0')) {isCorrect=false; break;}

            }

        }
        if(isCorrect) answer++;
    }
    return;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    vector<char> v, friends1;
    vector<bool> Exist(8, false);
    friends1.push_back('A'); friends1.push_back('C'); friends1.push_back('F'); friends1.push_back('J'); friends1.push_back('M'); friends1.push_back('N'); friends1.push_back('R'); friends1.push_back('T');
    answer=0;
    dfs(v, 0, data, friends1, Exist);

    return answer;
}