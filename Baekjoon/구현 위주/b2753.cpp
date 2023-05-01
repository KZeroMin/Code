#include <iostream>
using namespace std;

int main(){
    int year, a, b, c;
    cin >> year;

    a = year%4;
    b = year%100;
    c = year%400;

    if(year < 1 && year > 4000){
        return 0;
    }

    if(c == 0){
        cout << 1;
        return 0;
    }
    if(a == 0 && b != 0){
        cout << 1;
        return 0;
    }
    else if(b == 0 && c != 0){
        cout << 0;
        return 0;
    }
    else{
        cout << 0;
        return 0;
    }
}