#include <iostream>
using namespace std;

int main(){
    int N, result;
    cin >> N;
    result = 1;
    for(int i=1; i<=N; i++){
        result *= i;
    }
    cout << result;
}