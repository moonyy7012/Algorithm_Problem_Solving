#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s(numbers.size());
    for(int i=0, len=numbers.size(); i<len; i++)
        s[i] = to_string(numbers[i]);

    sort(s.begin(), s.end(), compare);

    if(s[0]=="0") return "0";
    for(int i=0, len=s.size(); i<len; i++)
        answer+=s[i];


    return answer;
}