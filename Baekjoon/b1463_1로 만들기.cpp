#include <iostream>
using namespace std;

int dp[1000001];
/*
        1   2   3   4   5   6   7   8   9   10
계산     0   1   1   2   3   2   3   3   2   3
*/

/*
4 -> 2 -> 1
5 -> 4 -> 2 -> 1
6 -> 2 -> 1
7 -> 6 -> 2 -> 1
8 -> 4 -> 2 -> 1
9 -> 3 -> 1
10 -> 9 -> 3 -> 1
*/

// 10 -> 9 -> 3 -> 1
int main(){
    int N;
    cin >> N;   // 정수 N입력
    dp[1] = 0;
    
    for(int i=2; i<=N; i++){
        if(i%2 != 0 && i%3 != 0){
            dp[i] = dp[i-1] + 1;
        }
        else if(i%2 == 0 && i%3 == 0){
            if(dp[i/2] + 1 < dp[i/3] + 1){
                dp[i] = dp[i/2] + 1;
            }
            else{
                dp[i] = dp[i/3] + 1;
            }
        }
        else if(i%2 == 0){
            if(dp[i/2] + 1 < dp[i-1] + 1){
                dp[i] = dp[i/2] + 1;
            }
            else{
                dp[i] = dp[i-1] + 1;
            }
        }
        else{
            if(dp[i/3] + 1 < dp[i-1] + 1){
                dp[i] = dp[i/3] + 1;
            }
            else{
                dp[i] = dp[i-1] + 1;
            }
        }
    }

    
    cout << dp[N];

    return 0;
}