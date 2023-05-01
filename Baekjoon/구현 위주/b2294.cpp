#include <iostream>
using namespace std;
int coin[100];
int dp[10001];
/*
    1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
1   1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
5   0  0  0  0  1  2  3  4  5   2   3   4   5   6   3
12  0  0  0  0  0  0  0  0  0   0   0   1   2   3   3
*/
int min(int a, int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int n, k;
    cin >> n >> k;  // n = 동전 수, k = 동전의 합
    
    fill(dp+1, dp+10001, 10001);
    
    for(int i=0; i<n; i++){
        cin >> coin[i];
        for(int j=coin[i]; j<=k; j++){
            dp[j] = min(dp[j], dp[j-coin[i]]+1);
        }
    }

    if(dp[k] != 10001){
        cout << dp[k];
    }
    else{
        cout << -1;
    }

    return 0;
}