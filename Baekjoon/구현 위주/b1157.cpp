#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[200];

int main(){
    string str;
    char alpa;
    int max,asc;
    max = 0;
    cin >> str;

    for(int i=0; i<str.length(); i++){
        alpa = tolower(str[i]);
        arr[int(alpa)] += 1;

        if(arr[int(alpa)] > max){
            max = arr[int(alpa)];
            asc = int(alpa);
        }
    }

    sort(arr, arr+200, greater<int>());
    if(arr[0] != arr[1]){
        alpa = char(asc);
        alpa = toupper(alpa);
        printf("%c\n", alpa);
    }
    else{
        cout << "?";
    }

    return 0;

}