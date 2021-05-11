#include <string>
#include <vector>
#define pii pair<int, int>
#include<iostream>

using namespace std;


string solution(vector<int> numbers, string hand) {
    string answer = "";

    pii left = make_pair(0, 3);
    pii right = make_pair(2, 3);
    vector<pii> xy(10);
    xy[0]=make_pair(1, 3);
    for(int i=1; i<10; i++)
        xy[i]=make_pair((i-1)%3,(i-1)/3);


    for(int i=0, len=numbers.size(); i<len; i++){
        if(numbers[i]%3==1) {
            answer+='L';
            left = xy[numbers[i]];

        }
        else if((numbers[i])&&(numbers[i]%3==0)) {
            answer+='R';
            right = xy[numbers[i]];

        }
        else{
            int lenL = abs((left.first)-(xy[numbers[i]].first))+abs((left.second)-(xy[numbers[i]].second));
            int lenR = abs((right.first)-(xy[numbers[i]].first))+abs((right.second)-(xy[numbers[i]].second));
            if(lenL<lenR) {
                answer+='L';
                left = xy[numbers[i]];
            }
            else if(lenL>lenR){
                answer+='R';
                right = xy[numbers[i]];
            }
            else{
                if(!hand.compare("right")){
                    answer+='R';
                    right=xy[numbers[i]];
                }
                else{
                    answer+='L';
                    left=xy[numbers[i]];
                }
            }
        }
    }

    return answer;
}