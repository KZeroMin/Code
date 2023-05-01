#include <iostream>
using namespace std;

int main(){
    int Fprice, N, number, price, SUM;
    cin >> Fprice;
    cin >> N;
    SUM = 0;

    for(int i=0; i<N; i++){
        cin >> price >> number;
        SUM += price*number;
    }

    if(Fprice == SUM){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;
}