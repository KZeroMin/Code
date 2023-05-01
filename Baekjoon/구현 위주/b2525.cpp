#include <iostream>
using namespace std;

int main(){
    int Hour, Min, SpendTime, Min_sum;
    cin >> Hour >> Min; // 현재시간 입력
    cin >> SpendTime;   // 소요시간 입력

    Min_sum = Min + SpendTime;
    
    if(Min_sum >= 60){
       Hour += Min_sum / 60;
       if(Hour >= 24){
        Hour -= 24;
       }
       Min = Min_sum % 60;

       cout << Hour << " " << Min;
    }
    else{
        cout << Hour << " " << Min_sum;
    }

    return 0;
}