#include <iostream>
using namespace std;

int main(){
    int num1, num2, rev1, rev2;
    int div = 100;
    int mul = 1;
    rev1 = rev2 = 0;
    cin >> num1 >> num2;

    for(int i=0; i<3; i++){
        rev1 += (num1/div)*mul;
        rev2 += (num2/div)*mul;
        mul = mul*10;
        num1 = num1 - (num1/div)*div;
        num2 = num2 - (num2/div)*div;
        div = div/10;
    }
    
    if(rev1 > rev2){
        cout << rev1;
    }
    else{
        cout << rev2;
    }

    return 0;
}