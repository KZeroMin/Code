#include <iostream>
using namespace std;

int Dice_num[7];

int main(){
    int Dice1, Dice2, Dice3, Dice;
    int overlap = 0;
    int award = 0;
    int Max_num = 0;
    cin >> Dice1 >> Dice2 >> Dice3;

    Dice_num[Dice1] += 1;
    Dice_num[Dice2] += 1;
    Dice_num[Dice3] += 1;

    for(int i = 1; i <= 6; i++){
        if(Dice_num[i] > overlap){
            overlap = Dice_num[i];
            Dice = i;
        }
        if(Dice_num[i] > 0 && i > Max_num){
            Max_num = i;
        }
    }

    if(overlap == 3){
        cout << 10000 + Dice * 1000;
    }
    else if(overlap == 2){
        cout << 1000 + Dice * 100;
    }
    else{
        cout << Max_num * 100;
    }

    return 0;
}