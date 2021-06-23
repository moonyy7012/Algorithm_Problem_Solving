#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> v(1000001, false);
    for(int i=2; i<=n/2; i++){
        for(int j=2; i*j<=n; j++)
            v[i*j]=true;
    }
    for(int i=2; i<=n; i++)
        if(!(v[i]))answer++;

    return answer;
}