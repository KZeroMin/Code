#include <iostream>
using namespace std;
int dp[1001];
int min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}
/*
    1  2  3  4  5
1   1  2  3  4  5
3   0  0  1  2  3

홀수면 SK, 짝수면 CY
*/
int main(){
    int N;
    cin >> N;
    fill(dp+1, dp+1001, 1001);

    for(int j=1; j<=N; j++){
        dp[j] = min(dp[j], dp[j-1]+1);
    }
    for(int j=3; j<=N; j++){
        dp[j] = min(dp[j], dp[j-3]+1);
    }

    if(dp[N]%2 == 0){
        cout << "CY";
    }
    else{
        cout << "SK";
    }

    return 0;

}