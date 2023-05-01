#include <iostream>
#include <queue>
using namespace  std;

queue<int> Router;

int main(){
    int B_size;
    int R_num;

    cin >> B_size;

    while(R_num != -1){
        cin >> R_num;
        if(R_num > 0 && Router.size() < B_size){
            Router.push(R_num);
        }
        else if(R_num == 0){
            Router.pop();
        }
    }

    if(Router.size() > 0){
        while(Router.size() > 0){
            cout << Router.front() << " ";
            Router.pop();
        }
    }
    else{
        cout << "empty";
    }

    return 0;
}