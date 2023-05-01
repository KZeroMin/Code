#include <iostream>
using namespace std;

/*
마지막 돌을 가져가는 사람이 승리 (승리시 1)
    1   2   3   4   5   6   7   8   9   10
SK  1   0   1   0   1   0   
CY  0   1   0   1   0   1
*/
// DP로 시도하기엔 메모리 초과 우려
// 홀수이면 SK, 짝수이면 CY
int main(){
    long long N;
    cin >> N;
    if(N == 1){
        cout << "SK";
        return 0;
    }
    else if(N == 2){
        cout << "CY";
        return 0;
    }


    if(N % 2 == 0){
        cout << "CY";
        return 0;
    }
    else{
        cout << "SK";
        return 0;
    }

    return 0;
}