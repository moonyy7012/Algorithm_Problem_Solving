#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len=s.length();
    if(len==1) return 1;
    int mid=len/2;
    vector<int> leng(mid+1,0);
    leng[0]=1001;
    for(int i=1; i<=mid; i++){
        vector<string> comp;
        vector<int> cnt;
        for(int j=0; j<len; j+=i){
            string a="";
            for(int k=j; k<j+i; k++)
                if(k<len)a+=s[k];

            if(comp.size()>0){
                if(a==comp[comp.size()-1])
                    cnt[cnt.size()-1]++;
                else{
                    comp.push_back(a);
                    cnt.push_back(1);
                }
            }
            else{
                comp.push_back(a);
                cnt.push_back(1);
            }
        }
        for(int j=0, len3=comp.size(); j<len3; j++){
            int p=1, n=0;
            if(cnt[j]!=1){
                while(1){
                    if(cnt[j]/p) n++;
                    else break;
                    p*=10;
                }
            }
            leng[i]+=(comp[j].length()+n);
        }
    }


    answer=*min_element(leng.begin(), leng.end());


    return answer;
}