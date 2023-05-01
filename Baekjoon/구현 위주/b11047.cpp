#include <iostream>
using namespace std;

//동전 지갑
int coin[11];

int main(){
    int N, K, count;
    // 사용 동전 수
    count = 0;

    // 동전 종류, 금액 입력
    cin >> N >> K;

    // 동전 입력
    for(int i=1; i<=N; i++){
        cin >> coin[i];
    }
    
    // 큰 금액부터 나누기, 나눈 몫 만큼 해당 동전에서 빼기
    for(int i = N; i>0; i--){
        count += K/coin[i];
        K = K%coin[i];
    }

    cout << count;

    return 0;
}