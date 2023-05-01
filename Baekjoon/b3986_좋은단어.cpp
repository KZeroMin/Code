#include <iostream>
#include <string>
#include <stack>
using namespace std;


int main(){

    int N, size, num;
    int result = 0;
    string input;
    cin >> N;

    for(int i=0; i<N; i++){
        stack<int> S;
        cin >> input;
        size = input.length();

        for(int k=0; k<size; k++){
            
            if(input[k] == 'A'){
                num = 1;
                //cout << 2 << endl;
            }
            else if(input[k] == 'B'){
                num = 2;
                //cout << 3 << endl;
            }

            if(S.size() == 0){
                S.push(num);
            }
            else if(S.size() != 0){
                if(S.top() == num){
                    S.pop();
                }
                else{
                    S.push(num);
                }
            }
        }

        if(S.size() == 0){
            result += 1;
        }
    }
    
    cout << result;

    return 0;

}
