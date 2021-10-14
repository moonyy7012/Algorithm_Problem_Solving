#include <string>
#include <vector>

using namespace std;
// 특정 년도, 특정월의 말일은 배열로 지정해 놓음
int lastday[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7]={"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
string solution(int a, int b) {
    int days = 0;
    for(int i=1; i<a; i++)
        days+=lastday[i];
    
    days+=b;
//     days : 1월 1일(금)이 1
    return day[days%7];
    
}
