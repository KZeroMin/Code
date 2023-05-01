#include <iostream>
using namespace std;
int num[10];

int main(){
    int A, B, C, mul, result;
    int check = 0;
    int div = 10;
    cin >> A >> B >> C;
    mul = A*B*C;

    while(mul != 0){
        num[mul%div] += 1;
        mul = mul/10;
    }

    for(int i=0; i<10; i++){
        cout << num[i] << "\n";
    }

    return 0;
    
}