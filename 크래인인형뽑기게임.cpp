#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, n = board.size();
    vector<int> bascket;

    for(int i=0, len=moves.size(); i<len; i++){
        for(int j=0; j<n; j++){
            if(board[j][moves[i]-1]) {
                if(bascket.size()&&(bascket[bascket.size()-1]==board[j][moves[i]-1])) {
                    bascket.pop_back();
                    answer+=2;   //터진 인형의 개수는 한 번에 2개씩이므로
                }
                else{
                    bascket.push_back(board[j][moves[i]-1]);
                }
                board[j][moves[i]-1]=0;
                break;
            }
        }
    }
    return answer;
}