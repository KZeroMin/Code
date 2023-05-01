#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int stack[51] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_of_input;
    int len_of_input;
    int stack_idx = 1;
    string input;    
    cin >> num_of_input;
    string output[num_of_input];

    stack[0] = -1;

    for(int i=0; i<num_of_input; i++){
        cin >> input;
        len_of_input = input.length();
        for(int j=0; j<len_of_input; j++){
            if(input[j] == '('){
                stack_idx += 1;
                stack[stack_idx] = 1;
            }
            else if(input[j] == ')'){
                stack_idx -= 1;
                if(stack_idx <= 0){
                    output[i] = "NO";
                    break;
                }
                stack[stack_idx] = 0;
            }
        }

        if(stack[stack_idx-1] == -1){
            output[i] = "YES";
            stack_idx = 1;
        }
        else{
            output[i] = "NO";
            stack_idx = 1;
        }
    }

    for(int i=0; i<num_of_input; i++){
        cout << output[i] << '\n';
    }

    return 0;
    
}