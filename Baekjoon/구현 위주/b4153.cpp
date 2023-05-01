#include <iostream>
using namespace std;

int length[3];

int main(){

    while(1){
        int max = 0;
        int sum = 0;

        for(int i=0; i<3; i++){
            cin >> length[i];
            if(length[i] == 0){
                return 0;
            }
            if(length[i] > max){
                max = length[i];
            }
        }

        for(int i=0; i<3; i++){
            if(length[i] != max){
                sum += length[i]*length[i];
            }
        }

        max = max*max;

        if(max == sum){
            cout << "right\n";
        }
        else{
            cout << "wrong\n";
        }

    }

    return 0;
    

}