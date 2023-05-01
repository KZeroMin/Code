#include <iostream>
#include <string>
using namespace std;

typedef struct List{
    string color;
    int value;
}List;

int main(){
    List list[10];
    string color1, color2, color3;
    long long int result = 0;
    list[0].color = "black";
    list[0].value = 0;

    list[1].color = "brown";
    list[1].value = 1;

    list[2].color = "red";
    list[2].value = 2;

    list[3].color = "orange";
    list[3].value = 3;

    list[4].color = "yellow";
    list[4].value = 4;

    list[5].color = "green";
    list[5].value = 5;

    list[6].color = "blue";
    list[6].value = 6;

    list[7].color = "violet";
    list[7].value = 7;

    list[8].color = "grey";
    list[8].value = 8;    

    list[9].color = "white";
    list[9].value = 9; 

    cin >> color1 >> color2 >> color3;

    for(int i=0; i<10; i++){
        if(list[i].color == color1){
            result += list[i].value*10;
        }
    }
    for(int i=0; i<10; i++){
        if(list[i].color == color2){
            result += list[i].value;
        }
    }
    if(color3 == "black"){
        result *= 1;
    }
    else{
        for(int i=0; i<10; i++){
            if(list[i].color == color3){
                for(int j=0; j<list[i].value; j++){
                    result *= 10;
                }
            }
        }
    }
    cout << result;

    return 0;
}