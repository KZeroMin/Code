#include <iostream>
using namespace std;

int main(){
    int number, original;
    int sum = 0;
    int mul = 10;
    int div = 10;


    while(1){
        // 입력
        cin >> number;
        original = number;

        while(1){
            if(number % div == original){
                div = div/10;
                break;
            }
            else{
                div = div*10;
            }
        }

        // 입력 종료
        if(number == 0){
            return 0;
        }

        // 펠리드롬 여부 체크
        while(number > 0){
            sum += (number%mul)*div;
            number = (number - number%mul)/10;
            if(div > 1){
                div = div/10;
            }
        }

        // 출력 
        if(original == sum){
            cout << "yes" << "\n";
        }
        else{
            cout << "no" << "\n";
        }
        sum = 0;
    }




    

    return 0;
}