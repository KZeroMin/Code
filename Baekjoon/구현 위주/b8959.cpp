#include <iostream>
using namespace std;

int main(){
    int N;
    int status = 0;
    int sum = 0;
    string S;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> S;
        for(int j=0; j<S.length(); j++){
            if(S[j] == 'O'){
                status += 1;
                sum += status;
            }
            else if(S[j] == 'X'){
                status = 0;
            }
        }
        cout << sum << "\n";
        status = sum =0;
    }

    return 0;

}