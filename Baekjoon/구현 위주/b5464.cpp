#include <iostream>
#include <queue>
using namespace std;

int park[101][101] = {0,};
int car[2001][2001] = {0,};
queue<int> Q;

int main(){
    int N, M, weight, cmd;
    int income = 0;
    
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        cin >> park[1][i];
    }
 
    for(int i=1; i<=M; i++){
        car[i][0] = i;
        cin >> car[1][i];
    }

    while(1){
        cin >> cmd;
        
    }



    return 0;

}