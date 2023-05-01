#include <iostream>
using namespace std;

int main(){
    int x, y; // 좌표를 저장할 변수
    cin >> x;
    cin >> y;

    if(x > 0 && y > 0){
        cout << '1';
    }
    else if(x < 0 && y > 0){
        cout << '2';
    }
    else if(x < 0 && y < 0){
        cout << '3';
    }
    else{
        cout << '4';
    }

    return 0;
}