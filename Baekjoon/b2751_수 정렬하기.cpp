#include <iostream>
using namespace std;

// Counting sort로 해보자
// 절댓값이 1,000,000보다 작거나 같은 정수임을 주의
// 0 ~ 1000000 까진 음수를 저장, 이후 양수 저장
int counting[2000002];


int main(){
    int N, number;
    cin >> N;
    
    //입력
    for(int i=0; i<N; i++){
        cin >> number;
        if(number < 0){ // 음수일때
            counting[-number]++;
        }
        else{
            counting[1000001 + number]++;
        }
    }
    // 출력
    for(int i=1000000; i>=0; i--){
        for(int j=0; j<counting[i]; j++){
            cout << -i << "\n";
        }
    }
    for(int i=1000001; i<=2000001; i++){
        for(int j=0; j<counting[i]; j++){
            cout << i-1000001 << "\n";
        }
    }

    return 0;
}