#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> ret(n);
    for(int i=0; i<n; i++)
        ret[i]=arr1[i]|arr2[i];

    for(int i=0; i<n; i++){
        int twoD=ret[i];
        vector<int> vectwoD;
        string s="";
        while(twoD){
            vectwoD.push_back(twoD%2);
            twoD/=2;
        }
        int len = vectwoD.size();
        for(int j=0; j<n-len; j++)
            s+=' ';


        for(int j=len-1; j>=0; j--)
            s+=(vectwoD[j]?'#':' ');

        answer.push_back(s);

    }


    return answer;
}