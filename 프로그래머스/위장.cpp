#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;

    for(int i=0, len=clothes.size(); i<len; i++){
        //의상종류(key)가 같은 것을 map에서 찾아 iterator 저장
        map<string, int>::iterator it = m.find(clothes[i][1]);
        //iterator가 end()이면 map의 처음부터 끝까지 검색하여도 발견되지 않은 경우
        if(it==m.end())
            m.insert(make_pair(clothes[i][1],1));
        else
            (it->second)++;
    }
    for(map<string, int>::iterator i=m.begin(); i!=m.end(); i++)
        answer*=(i->second)+1;

    return answer-1;
}