#include <iostream>
using namespace std;
int swc[101];

void Change(int k){
    if(swc[k] == 1){
        swc[k] = 0;
    }
    else{
        swc[k] = 1;
    }
}

int main(){
    int s_num, s_condition, students, sex, assigned_num;
    int LHS, RHS;
    cin >> s_num;
    // 스위치 상태 입력
    for(int i=1; i<= s_num; i++){
        cin >> s_condition;
        swc[i] = s_condition;
    }
    // 학생 수 입력
    cin >> students;

    for(int j=0; j<students; j++){
        cin >> sex >> assigned_num;

        LHS = assigned_num-1;
        RHS = assigned_num+1;

        if(sex == 1){
            for(int k=1; k<=s_num; k++){
                if((k%assigned_num) == 0){
                    Change(k);
                }
            }
        }
        if(sex == 2){
            while(1){
                if(LHS < 1 || RHS > s_num){
                    for(int i=LHS+1; i<=RHS-1; i++){
                        Change(i);
                    }
                    break;
                }
                else if(swc[LHS] != swc[RHS]){
                    for(int i=LHS+1; i<=RHS-1; i++){
                        Change(i);
                    }
                    break;
                }
                else{
                    LHS = LHS - 1;
                    RHS =RHS + 1;
                }
            }
        }
    }

    for(int i=1; i<=s_num; i++){
        cout << swc[i];
        if((i%20) == 0){
            cout << "\n";
        }
        else{
            cout << " ";
        }
    }

    return 0;

}