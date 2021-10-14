#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int div[4]={0,1,2,4};
    int rest[3]={4, 1, 2};

    int r;
    vector<int> v;
    while(n){
        r=n%3;
        v.push_back(rest[r]);
        n/=3;
        if(r==0) n--;
    }
    for(int i=v.size()-1; i>=0; i--)
        answer+='0'+(char)v[i];


    return answer;
}
