#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int num;
    int sum = 0;
    int center;
    int arr[5];
    for(int i=0; i<5; i++){
        cin >> num;
        arr[i] = num;
        sum += num;
    }
    sort(arr, arr+5);
    cout << sum/5 << endl;
    cout << arr[2] << endl;;

    return 0;
}