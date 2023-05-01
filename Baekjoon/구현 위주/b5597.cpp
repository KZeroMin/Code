#include <iostream>
using namespace std;

int students[31] = {0, };

int main(){
    int num;
    for(int i=0; i<28; i++){
        cin >> num;
        students[num] = 1;
    }

    for(int i=1; i<=30; i++){
        if(students[i] != 1){
            cout << i << '\n';
        }
    }

    return 0;
}