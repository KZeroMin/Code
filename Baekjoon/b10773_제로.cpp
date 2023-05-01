#include <iostream>
#include <stack>
using namespace std;

stack<int> S;

int main(){
    int N, num, size;
    long sum = 0;

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> num;

        if(num == 0){
            S.pop();
        }
        else{
            S.push(num);
        }

    }

    if(S.size() == 0){
        cout << 0;
    }
    else{
        size = S.size();
        for(int i=0; i<size; i++){
            sum += S.top();
            S.pop();
        }
        cout << sum;
    }

    return 0;
}