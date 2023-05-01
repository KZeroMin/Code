#include <iostream>
using namespace std;

int main(){
    int N, X;
    int j=0;
    cin >> N >> X;
    int arr[N], arr_p[N];

    for(int i=0; i<N; i++){
        cin >> arr[i];
        if(arr[i] < X){
            arr_p[j] = arr[i];
            j++;
        }
        
    }
    for(int i=0; i<j; i++){
        cout << arr_p[i] << " ";
    }
    
    return 0;
}