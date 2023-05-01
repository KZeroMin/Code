#include <iostream>

using namespace std;

int main(){

    double A,B;

    cin >> A >> B;

    if(A>0 && B<10){
        cout.precision(9);
        cout << fixed;
        cout << A/B;
    }
    
    return 0;
}           