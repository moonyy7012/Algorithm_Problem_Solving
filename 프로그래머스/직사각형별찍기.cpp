#include <iostream>

using namespace std;

int main(void) {
    int col, row;
    cin>>col>>row;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cout<<'*';
        cout<<"\n";
    }

    return 0;
}