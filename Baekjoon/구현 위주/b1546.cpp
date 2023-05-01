#include <iostream>
using namespace std;

float fake(int M, int score){
    float sc;
    sc = score/M*100;
    return sc;
}

int main(){

    int M = 0;
    int N, score;
    float avg = 0;
    cin >> N;

    int array[N];

    for(int i=0; i<N; i++){
        cin >> array[i];
        if(array[i] > M){
            M = array[i];
        }
    }

    for(int i=0; i<N; i++){
        avg += (float)array[i]/M*100;
    }

    cout << avg/N;

    return 0;




}