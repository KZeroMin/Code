#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int num, index;
    int max = 0;
    int arr[9];

    for(int i=0; i<9; i++){
        cin >> num;
        arr[i] = num;

        if(max < num){
            max = num;
            index = i+1;
        }
    }

    cout << max << "\n";
    cout << index;

    return 0;

}