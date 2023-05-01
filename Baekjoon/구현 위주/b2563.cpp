#include <iostream>
#include <algorithm>
using namespace std;

int map[101][101]; // 하얀 도화지

int main(){
    int N, X_ray, Y_ray;
    int Sum = 0;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> X_ray >> Y_ray;

        for(int x=X_ray; x<=(X_ray+10); x++){   
            for(int y=Y_ray; y<=(Y_ray+10); y++){
                if(map[x][y] != 1 || map[x][y] >= 1){
                    map[x][y] = 1;
                }
            }
        }
        
    }

    for(int x=0; x<=100; x++){
        for(int y=0; y<=100; y++){
            if(map[x][y] == 1){
                Sum = Sum + 1;
            }
    }

    //cout << Sum;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
    }
}