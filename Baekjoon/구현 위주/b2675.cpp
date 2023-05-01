#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int T, N;
    string S;
    cin >> N;
    for(int k=0; k<N; k++){
        cin >> T >> S;
        for(int i=0; i<S.length(); i++){
            for(int j=0; j<T; j++){
                cout << S[i];
            }
        }
        cout << endl;
    }

    return 0;
}