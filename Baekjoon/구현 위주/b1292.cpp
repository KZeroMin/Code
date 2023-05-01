#include <iostream>
using namespace std;

int array[1001];

int main(){
    int A, B, index, sum;
    sum = 0;
    index = 1;
    cin >> A >> B;

    for(int i = 1; i<= B; i++){
        for(int j=1; j<=i; j++){
            array[index] = i;
            if(index > 1000){
                break;
            }
            index++;
        }
    }

    for(int i = A; i <= B; i++){
        sum += array[i];
    }

    cout << sum;
    
    return 0;



}