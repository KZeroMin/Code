#include <iostream>
using namespace std;

int main(){
    int n1, n2, sum;
    sum = 0;
    cin >> n1 >> n2;

    sum += n1*(n2%10);
    cout << n1*(n2%10) << endl;
    n2 = (n2 - (n2%10))/10;


    sum += n1*(n2%10)*10;
    cout << n1*(n2%10) << endl;
    n2 = (n2 - (n2%10))/10;


    sum += n1*(n2%10)*100;
    cout << n1*(n2%10) << endl;


    cout << sum << endl;

    return 0;

}