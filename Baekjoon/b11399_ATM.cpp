#include <iostream>
#include <algorithm>
using namespace std;

int greedy[1001];

int main(){
    int N, total, sum;
    total = 0, sum = 0;
    cin >> N;

    fill(greedy, greedy+1001, 9999);

    for(int i = 0; i<N; i++){
        cin >> greedy[i];
    }

    sort(greedy, greedy+1001);

    for(int i=0; i < N; i++){
        sum += greedy[i];
        total += sum;
    }

    cout << total;

    return 0;
    
}