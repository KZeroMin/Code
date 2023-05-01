#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> S_LR;
stack<int> S_SK;
stack<int> ERROR;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int Num_skill = 0;
    cin >> N;

    char CMD[N];
    char skill;
    cin >> CMD;

    for(int i=0; i<N; i++){
        skill = CMD[i];

        if(skill == 'L'){
            S_LR.push(1);
        }
        else if(skill == 'R'){
            if(S_LR.size() != 0){
                S_LR.pop();
                Num_skill += 1;
            }
            else{
                ERROR.push(1);
                break;
            }

        }
        else if(skill == 'S'){
            S_SK.push(1);

        }
        else if(skill == 'K'){
            if(S_SK.size() != 0){
                S_SK.pop();
                Num_skill += 1;
            }
            else{
                ERROR.push(1);
                break;
            }
        }
        else{   // 숫자일 때
            if(ERROR.size() == 0){
                Num_skill += 1;
            }
        }
    }

    cout << Num_skill;
    return 0;
}