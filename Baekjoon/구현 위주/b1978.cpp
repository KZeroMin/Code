#include <iostream>
using namespace std;

int input[1001] = {0};

int is_prime(int Max_number){
    int Prime = 0;

    for(int i=2; i<=Max_number; i++){
        for(int j=i+i; j<=Max_number; j+=i){
            input[j] = 0;
        }
    }

    for(int i=2; i<=Max_number; i++){
        if(input[i] != 0){
            Prime++;
        }
    }

    return Prime;
}


int main(){
    int Number_of_number;
    int Maxima = 0;
    int number;

    cin >> Number_of_number;

    for(int i=0; i<Number_of_number; i++){
        cin >> number;
        input[number] = number;
        if(number > Maxima){
            Maxima = number;
        }
    }

    cout << is_prime(Maxima);
    return 0;

}