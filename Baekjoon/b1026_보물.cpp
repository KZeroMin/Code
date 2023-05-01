#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int N, sum;
    sum = 0;
    cin >> N;

    int A[N];
    int B[N];

    for(int i = 0; i<N; i++){
        cin >> A[i];
    }

    for(int j = 0; j<N; j++){
        cin >> B[j];
    }

    sort(A, A+N);
    sort(B, B+N);
    
    for(int i = 0; i<N; i++){
        //cout << "A: " << A[i] << " B: " << B[N-(i+1)] << endl;
        sum += A[i] * B[N-(i+1)];
    }

    cout << sum;
    return 0;

}