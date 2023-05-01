#include <iostream>
using namespace std;

int coin[100];
int dp[10001];

/*
        1  2  3  4  5  6  7  8  9  10
    1   1  1  1  1  1  1  1  1  1  1
    2   0  1  1  2  2  3  3  4  4  5  
    5   0  0  0  0  1  1  2  2  3  4
 total  1  2  2  3  4  5  6  7  8  10


        1  2  3  4  5  6  7  8  9  10
    2   0  1  0  1  0  1  0  1  0  1
    5   0  0  0  0  1  0  1  0  1  1

*/

int main(){
    int n, k;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j] += dp[j-coin[i]];
        }
    }

    cout << dp[k];

    return 0;
}