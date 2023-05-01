#include <iostream>
#include <queue>
using namespace std;

queue<pair <int, int> > Q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int opus;
    int tmp1, tmp2, loop;

    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> opus;
        Q.push(pair<int, int>(i, opus));
    }

    while(Q.size() != 1){
        loop = Q.front().second;

        for(int i=0; i<loop-1; i++){
            tmp1 = Q.front().first;
            tmp2 = Q.front().second;
            Q.pop();

            Q.push(pair<int, int>(tmp1, tmp2));
        }
        
        Q.pop();
    }

    cout << Q.front().first;

    return 0;

}