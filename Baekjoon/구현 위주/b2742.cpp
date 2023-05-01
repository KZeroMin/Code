#include <iostream>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    if(N > 100000){
        return 0;
    }
    for(int i=N; i>0; i--){
        cout << i << "\n";
    }
    return 0;
}