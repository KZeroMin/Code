#include <iostream>
#include <algorithm>

using namespace std;
int dp[10001] = {};
int coin[101];

int Min(int a, int b){
	if(a > b){
		return b;
	}
	else{
		return a;
	}
}

int main(){
	int n, k;
	cin >> n >> k;	//동전 수, 합 입력

	fill(dp+1, dp+10001, 99999);

	for(int i=1; i<=n; i++){	//동전 입력
		cin >> coin[i];
		for(int j=coin[i]; j<=k; j++){
			dp[j] = Min(dp[j], dp[j-coin[i]]+1);
		}
	}

	if(dp[k] == 99999){
		cout << -1;
	}
	else{
		cout << dp[k];
	}

	return 0;

}