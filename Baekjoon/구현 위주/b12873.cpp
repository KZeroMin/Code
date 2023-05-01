#include <iostream>
#include <queue>
using namespace std;

queue<int> Queue;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int P_num, size;
    int tmp;
    long loop;
    long lavel = 1;

    cin >> P_num;

    for(int i=1; i<=P_num; i++){
        Queue.push(i);
    }

    while(Queue.size() != 1){
        loop = (lavel * lavel * lavel)%Queue.size();
        size = Queue.size();
        if(loop == 0){
            for(int i=0; i<size-1; i++){
                tmp = Queue.front();
                Queue.pop();
                Queue.push(tmp);
            }
            Queue.pop();
        }
        else{
            for(int i=0; i<loop-1; i++){
                tmp = Queue.front();
                Queue.pop();
                Queue.push(tmp);
            }
            Queue.pop();
        }
        lavel++;
    }

    cout << Queue.front();

    return 0;

}