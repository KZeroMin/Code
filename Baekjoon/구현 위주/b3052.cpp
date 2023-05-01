#include <iostream>
using namespace std;
int arr[1001];

int main(){
    int num;
    int count = 0;

    for(int i=0; i<10; i++){
        cin >> num;
        arr[num%42] += 1;
    }

    for(int i=0; i<1001; i++){
        if(arr[i] > 0){
            count += 1;
        }
    }
    cout << count;
    return 0;
}