#include <iostream>
using namespace std;

int card[2000] = {0,};

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int N, M;
    cin >> N;
    M = N;
    if(N == 1){
        cout << 1;
        return 0;
    }

    for(int i=1; i<=N; i++){
        if(card[i] == 0){
            card[i] = i;
        }
        if(i%2 == 0){
            card[N + 1] = card[i];
            N = N+1;
        }
        else{
            cout << card[i] << " ";
        }
        
    }

    return 0;
}