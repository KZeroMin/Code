#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int T, a, b, data, computer; 

    cin >> T;

    for(int i=0; i<T; i++){
        data = 1;
        cin >> a >> b;
        if(b%4 == 0){
            data = pow(a, 4);
        }
        else{
            data = pow(a, b%4);
        }
        
        if(data%10 == 0){
            cout << 10 << "\n";
        }
        else{
            cout << data%10 << "\n";
        }
    }

    return 0;
}