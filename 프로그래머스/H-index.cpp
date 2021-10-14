#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    //오름차순 정렬
    sort(citations.begin(), citations.end());
    int sum=0;//논문 갯수
    //뒤의 논문부터 차례로 판별 
    for(int i=citations.size()-1; i>=0; i--){
        sum++;
        for(int j=citations[i]; j>citations[i-1]; j--){
            //count한 논문 갯수 >= (citations[현재] ~ citations[현재-1]) 인지 판별하여 해당하면 바로 최댓값인 answer 구하고 종료
            if(sum>=j) {
                answer=j;
                break;
            }
        }
        if(answer) break;
    }

    return answer;
}
