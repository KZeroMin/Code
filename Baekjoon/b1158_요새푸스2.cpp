#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, tmp;
    queue<int> Q;

    cin >> N >> K;

    for(int i=1; i<=N; i++){
        Q.push(i);
    }

    cout << '<';

    while(Q.size() > 1){
        for(int i=0; i< K-1; i++){
            tmp = Q.front();
            Q.push(tmp);
            Q.pop();
        }
        
        tmp = Q.front();
        cout << tmp << ", ";
        Q.pop();

    }

    tmp = Q.front();
    cout << tmp << ">";

    return 0;

}