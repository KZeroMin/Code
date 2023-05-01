#include <iostream>
using namespace std;
int coin[100];
int dp[10001];
/*
    1  2  3  4  5  6  7  8  9  10  11  12
1   1  1  1  1  1  1  1  1  1  1   1    1
2   1  2  2  3  3  4  4  5  5  6   6    7
5   1  2  2  3  4  5  6  7  8  10   
*/

int main(){
    int n, k;
    cin >> n >> k;  // n = 동전 수, k = 동전의 합
    
    //fill(dp+1, dp+10001, 1);
    
    for(int i=0; i<n; i++){
        cin >> coin[i];

        for(int j=coin[i]; j<=k+1; j++){
			if(i==0 && j%coin[i] == 0){
				dp[j] = 1;
			}
			else{
				dp[j] = dp[j] + dp[j-coin[i]];
			}
    	}
	}
	cout << dp[k+1];
    return 0;
}