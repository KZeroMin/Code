#include <iostream>
#include <algorithm>
using namespace std;

int bag[5001];

int main(){
    int N, a, b;
    int count = 0;
    cin >> N;
    bag[3] = bag[5] = 1;

    for(int i = 6; i <= N; i++){
        if(bag[i-3]){
            a = bag[i-3] + 1;
            bag[i] = a;
        }
        if(bag[i-5]){
            b = bag[i-5] + 1;
            if(a > b){
                bag[i] = b;
            }
            else{
                bag[i] = a;
            }
        }
    }

    if(bag[N] != 0){
        cout << bag[N];
    }
    else if(bag[N] == 0){
        cout << -1;
    }
    return 0;

}