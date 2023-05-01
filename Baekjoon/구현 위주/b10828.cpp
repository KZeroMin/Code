#include <iostream>
#include <stack>
using namespace std;

stack<int> S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int number;
    string cmd;

    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> cmd;

        if(cmd == "push"){
            cin >> number;
            S.push(number);
        }
        else if(cmd == "pop"){
            if(S.size() == 0){
                cout << -1 << "\n";
            }
            else{
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if(cmd == "size"){
            cout << S.size() << "\n";
        }
        else if(cmd == "empty"){
            if(S.size() == 0){
                cout << 1 << "\n";
            }
            else{
                cout << 0 << "\n";
            }
        }
        else if(cmd == "top"){
            if(S.size() == 0){
                cout << -1 << "\n";
            }
            else{
                cout << S.top() << "\n";
            }
        }



    }

    return 0;
}
