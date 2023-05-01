#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int N, num;
    int result = 0;
    cin >> N;
    int arg[N];

    for(int i=0; i<N; i++){
        scanf("%2d", &num);
        arg[i] = num;
    }

    for(int i=0; i<N; i++){
        result += arg[i];
    }
    
    cout << result;

    return 0;
}