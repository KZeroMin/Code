#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> Queue;
    int N, K, tmp;
    cin >> N >> K;

    for(int i=1; i<=N; i++){
        Queue.push(i);
    }

    cout << "<";
    while(Queue.size() > 1){
        for(int i=1; i<K; i++){
            tmp = Queue.front();
            Queue.pop();
            Queue.push(tmp);
        }
        cout << Queue.front() << ", ";
        Queue.pop();
    }

    cout << Queue.front() << ">";

    return 0;
}