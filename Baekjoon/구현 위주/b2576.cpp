#include <iostream>
using namespace std;

int main(){
    int num;
    int min = 100;
    int sum = 0;
    for(int i=0; i<7; i++){
        cin >> num;
        if((num % 2)==1 || num == 1){
            sum += num;
            if(num < min){
                min = num;
            }
        }
    }
    if(sum == 0){
        cout << -1;
    }
    else{
        cout << sum << endl;
        cout << min;
    }

    return 0;
}