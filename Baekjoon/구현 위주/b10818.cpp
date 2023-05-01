#include <iostream>
using namespace std;

int arr[1000001];

int main(){
    int N, a, min, max;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a;
        arr[i] = a;
    }

    max = arr[0];
    min = arr[0];
    for(int j=0; j<N; j++){
        if(max < arr[j]){
            max = arr[j];
        }
        if(min > arr[j]){
            min = arr[j];
        }
    }

    cout << min << " " << max;
    return 0;
}