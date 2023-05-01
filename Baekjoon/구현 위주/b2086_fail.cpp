#include <iostream>
#include <algorithm>
using namespace std;
int fibonacci[9999999] = {0,};
long long nanugi = 1000000000;

int Fibo(int n){

    if(n <=1){
        fibonacci[n] = n;
        return fibonacci[n];
    }
    else if(fibonacci[n] != 0){
        return fibonacci[n];
    }
    else{
        fibonacci[n] = Fibo(n-1) + Fibo(n-2);
        return fibonacci[n];
    }
}

int main(){
    long long a,b;
    int sum_a, sum_b, total_sum, result;
    cin >> a >> b;

    for(int i=0; i<=b+2; i++){
        fibonacci[i] = Fibo(i);
    }

    if(a == b){
        cout << fibonacci[a];
    }
    else{
        sum_a = fibonacci[a+1] - 1;
        sum_b = fibonacci[b+2] - 1;
        total_sum = sum_b - sum_a;
        result = total_sum%nanugi;
        if(result < 0){
            cout << -result;
        }
        else{
            cout << result;
        }
        
    }

    return 0;
}