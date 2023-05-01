#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int star = N;

    for(int i=0; i<N; i++){
        for(int i=star; i>0; i--){
            cout << '*';
        }
        star -= 1;
        cout << '\n';
    }

    return 0;
}