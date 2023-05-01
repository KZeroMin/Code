#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n1, n2;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> n1 >> n2;
        cout << n1+n2 << "\n";
    }

    return 0;

}