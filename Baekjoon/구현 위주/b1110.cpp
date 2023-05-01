#include <iostream>
using namespace std;

int main(){
    int N, original, count, NewNumber;
    count = 0;
    cin >> N;
    original = N;   // 초기값 저장

    while(1){
        count++;
        NewNumber = (N%10)*10 + ((N/10) + (N%10))%10;

        if(NewNumber == original){
            cout << count;
            break;
        }
        else{
            N = NewNumber;
        }
    }

    return 0;
}