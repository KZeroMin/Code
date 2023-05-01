#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int> > Queue;
int ans[1001] = {0,};

int main(){
    int N;
    int Pizza;

    for(int i=1; i<=N; i++){
        cin >> Pizza;
        Queue.push(pair<int, int>(i, Pizza));
    }




}