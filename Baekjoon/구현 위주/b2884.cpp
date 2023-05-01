#include <iostream>
using namespace std;

int main(){
    int H, M, m;
    cin >> H >> M;

    if(M >= 45){
        cout << H << " " << M-45;
        return 0;
    }
    else{
        m = 45 - M;
        M = 60 - m;
    }

    if(H > 0){
        H = H - 1;
    }
    else if(H == 0){
        H = 23;
    }

    cout << H << " " << M;
    return 0;
}