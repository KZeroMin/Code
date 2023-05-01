#include <iostream>
#define Maxima 1000001

using namespace std;

int Array[Maxima] = {0, };

int main(){
    
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int Min, Max;
    cin >> Min >> Max;

    
    for(int i=1; i<=Max; i++){
        Array[i] = i;
    }

    for(int i=2; i<=Max; i++){
        if(Array[i] == 0) continue;

        for(int j = i+i; j<=Max; j+=i){
            Array[j] = 0;
        }
    }

    for(int i=Min; i<=Max; i++){
        if(Array[i] ==  0 || Array[i] == 1) continue;
        cout << i << '\n';
    }

    return 0;
}
