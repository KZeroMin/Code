#include <iostream>
using namespace std;

int coin[11];

int main(){
    int N, K, count;
    count = 0;
    cin >> N >> K;
    
    for(int i=1; i<=N; i++){
        cin >> coin[i];
    }

    for(int i = N; i>0; i--){
        count += K/coin[i];
        K = K%coin[i];
    }

    cout << count;

    return 0;
}