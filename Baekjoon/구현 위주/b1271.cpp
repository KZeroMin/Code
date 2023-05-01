#include <iostream>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    if(m >= 1 && n >= 1 && m <= 10000 && n <= 10000){
        cout << m/n << endl;
        cout << m%n << endl;
    }
    return 0;
}