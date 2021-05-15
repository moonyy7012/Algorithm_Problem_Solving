#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer="";
    for(int i=0, len=new_id.length(); i<len; i++){
        if(new_id[i]>='A' && new_id[i]<='Z')
            new_id[i]=(new_id[i]-'A'+'a');
    }
    for(int i=0; i<new_id.length(); i++){
        if(!((new_id[i]>='a'&&new_id[i]<='z') || (new_id[i]>='0'&&new_id[i]<='9') || (new_id[i]=='-') ||(new_id[i]=='_') || (new_id[i]=='.'))) {
//  문자열에서 특정위치 문자 삭제할 때 erase 사용. 매개변수에는 반드시 .begin(), .end()를 써서 인덱스 지정.
            new_id.erase(new_id.begin()+i, new_id.begin()+i+1);
            i--;
        }
    }

    int i=0;
    while(i<new_id.length()){
        if(new_id[i]=='.'&&new_id[i+1]=='.') {
            int first=i;
            i+=2;
            while(new_id[i]=='.') i++;
            new_id.erase(new_id.begin()+first+1, new_id.begin()+i);
            i=first;
        }
        i++;
    }
    if(new_id[0]=='.') new_id.erase(new_id.begin(), new_id.begin()+1);
    if(new_id[new_id.length()-1]=='.') new_id.erase(new_id.end()-1, new_id.end());

    if(new_id=="") new_id="a";
    if(new_id.length()>=16) {
        new_id.erase(new_id.begin()+15, new_id.end());
        if(new_id[new_id.length()-1]=='.') new_id.erase(new_id.end()-1, new_id.end());
    }
    if(new_id.length()<=2) while(new_id.length()<3) new_id+=(new_id[new_id.length()-1]);

    answer=new_id;
    return answer;
}