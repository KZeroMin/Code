#include <iostream>
#include <queue>
using namespace std;

queue<int> Q;
int input[1001] = {0,};

int main(){
    int N, W, L;
    int time = 0;
    int total_w = 0;

    cin >> N >> W >> L;

    for(int i=1; i<=N; i++){
        cin >> input[i];
    }

    for(int i=1; i<=N; i++){
        while(1){
            if(Q.size() == W){
                total_w -= Q.front();
                Q.pop();
            }

            if(total_w + input[i] <= L){
                break;
            }
            Q.push(0);
            time++;

        }
        Q.push(input[i]);
        total_w += input[i];
        time++;
    }
    cout << time + W;
    return 0;


}