#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int N, Max;
    int mul = 1;
    Max = 0;

    cin >> N;
    int Rope[N];

    for(int i = 0; i < N; i++){
        cin >> Rope[i];
    }

    sort(Rope, Rope+N);

    // 사용 로프는 동일 중량
    for(int i = N-1; i >= 0; i--){
        if(Rope[i] * mul > Max){
            Max = Rope[i] * mul;
        }
        mul++;
    }

    cout << Max;

    return 0;
}