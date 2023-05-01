#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> S;
queue<char> R_S;
int idx = 0;
int answer[100001] = {0, };

void POP(){
    S.pop();
    idx += 1;
    //cout << "-\n";
    R_S.push('-');

    if(S.size() != 0 && S.top() == answer[idx]){
        POP();
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, top_num;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> answer[i];
    }

    for(int i=1; i<=N; i++){
        S.push(i);
        //cout << "+\n";
        R_S.push('+');

        if(S.size() != 0 && S.top() == answer[idx]){
            POP();
        }
    }

    if(S.size() != 0){
        cout << "NO";
    }
    else{
        while(R_S.size() != 0){
            cout << R_S.front() << '\n';
            R_S.pop();
        }
    } 

    return 0;

}