#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    int num1, num2;
    int check;

    cin >> N;
    
    int A[N];
    for(int i=0; i<N; i++){
        cin >> num1;
        A[i] = num1;
    }
    sort(A, A+N);

    cin >> M;
    int Mrray[M];
    for(int i=0; i<M; i++){
        cin >> num2;
        Mrray[i] = num2;
    }
    for(int i=0; i<M; i++){

    if(binary_search(A, A+N, Mrray[i])){
        cout << "1\n";
    }
    else cout << "0\n";

    }

    return 0;

}