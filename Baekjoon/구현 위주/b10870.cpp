#include <iostream>
#include <algorithm>
using namespace std;
int fibonacci[21] = {0,};

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
    int n;
    cin >> n;

    cout << Fibo(n);

    return 0;
}