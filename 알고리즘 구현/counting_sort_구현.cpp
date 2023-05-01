#include <iostream>
using namespace std;

int Arr[1000];
int Brr[1000];
int seed = 400; // 고정 seed값
int Array_size; // 사용할 배열 크기
int Maxnum = 0; // Counting array 크기를 지정할 변수


void CountingSort(){
    int Counting[Maxnum+1];
    
    for(int i = 0; i < Maxnum+1; i++){  //Counting array 0으로 초기화
        Counting[i] = 0;
    }
    
    for(int i = 0; i < Array_size; i++){   // Arr 배열의 원소별로 카운트, Counting 배열 값 증가
        Counting[Arr[i]] += 1;
    }

    for(int i = 1; i <= Maxnum; i++){   // Counting 배열 index 1부터 누적으로 더하기
        Counting[i] = Counting[i] + Counting[i-1];
    }

    for(int i = Array_size; i >= 0; i--){   // 가장 끝에 있는 element부터 Brr에 삽입하며 sorting
        Brr[Counting[Arr[i]] - 1] = Arr[i];
        Counting[Arr[i]]  = Counting[Arr[i]] - 1;
    }

    cout << "\n\nSorted Array\n";   // sort된 최종 배열 Brr출력
    for(int i = 0; i < Array_size; i++){
        cout << Brr[i] << " ";
    }

    

}

int main(){
    
    int n, k;
    cout << "Enter array size (n <= 1000): ";   // n, k입력시 1000보다 클 경우 에러 메세지 출력 후, 프로그램 종료
    cin >> n;
    if(n > 1000){
        cout << "Error: n is bigger than 1000\n";
        return 0;
    }
    cout << "Enter range of random numbers (k <= 1000)): ";
    cin >> k;
    if(k > 1000){
        cout << "Error: k is bigger than 1000\n";
        return 0;
    }

    Array_size = n;
    srand(seed);

    cout << "Array\n";
    for(int i = 0; i < n; i++){ // n크기 만큼 random number로 배열 값 초기화, Sort전 array출력
        Arr[i] = rand()%(k+1);  // 0 ~ k 범위의 난수 생성
        if(Maxnum < Arr[i]){
            Maxnum = Arr[i];
        }
        cout << Arr[i] << " ";
    }

    CountingSort();

    return 0;
}