#include <iostream>
using namespace std;

int main(){

    int num, sum, part;

    cin >> num;


    for(int i=1; i < num; i++){
        sum = i;
        part = i;

        while(part > 0){
            sum += part % 10;
            part = part/10;
        }

        if(num == sum){
            cout << i << endl;
            return 0;
        }
    }

    cout << 0;

    return 0;
}