#include <iostream>

using namespace std;

int main(){

    int num, divisor, N;
    int array[50];
    int ptr;

    cin >> num; //약수의 개수 입력

    for(int i=0; i< num; i++){
        cin >> divisor;
        array[i] = divisor;
    }

    int max=array[0];
    int min=array[0];

    for(int i=0; i<num; i++){
        if(max < array[i]){
            max = array[i];
        }
        if(min > array[i]){
            min = array[i];
        }
    }
    

    N = min*max;

    cout << N << endl;

    return 0;

}