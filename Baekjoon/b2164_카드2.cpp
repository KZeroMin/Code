#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> Q;
    int number;
    int N;

    cin >> N;
    
    for(int i=1; i<=N; i++){
        Q.push(i);
    }

    while(Q.size() > 1){
        Q.pop();
        number = Q.front();
        Q.pop();
        Q.push(number);
    }
    cout << Q.front() << endl;
    return 0;

}