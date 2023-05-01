#include <iostream>
using namespace std;

int main(){
    int score;
    cin >> score;

    if(score >= 90){
        cout << "A";
        return 0;
    }
    else if(score >= 80 && score <= 89){
        cout << "B";
        return 0;
    }
    else if(score >= 70 && score <= 79){
        cout << "C";
        return 0;
    }
    else if(score >= 60 && score <= 69){
        cout << "D";
        return 0;
    }
    else{
        cout << "F";
        return 0;
    }
}