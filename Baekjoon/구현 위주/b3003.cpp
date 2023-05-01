#include <iostream>
using namespace std;

int main(){
    int K, Q, L, B, Kn, P;
    cin >> K >> Q >> L >> B >> Kn >> P;
    cout << 1-K << " " << 1-Q << " " << 2-L << " " << 2-B << " " << 2-Kn << " " << 8-P;
    return 0;
}