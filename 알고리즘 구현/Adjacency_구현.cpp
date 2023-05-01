/*
HW4 by 21800121 김영민
Reference
1.  강의 slide chapter 22. 
2.  Blog: https://coding-factory.tistory.com/596 (C++ Vector사용법 참조)  
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

char AdjMatrix[21][21]; //Adjacency array
char AdjMatrix_TP[21][21];  //Adjacency transpose array
vector<char> AdjList[21];   //Adjacency list
vector<char> AdjList_TP[21];    // Adjacency transpose list

int main(){
    string str;
    string input_data = "hw4_.data2.txt";    // input data file
    int len;

   ifstream fin;
   fin.open(input_data);
   getline(fin, str);   // data file의 첫 줄을 읽어온 후, (첫 줄의 length) / 2 개씩 두번째줄 부터 문자를 하나씩 읽어 옴
   len = str.length()/2;
   fin.close();

   AdjMatrix[0][0] = '\\';

   //Adj array생성
   fin.open(input_data);
   for(int i = 1; i<=len; i++){
       fin >> AdjMatrix[0][i];
   }
   for(int i = 1; i <= len; i++){
       for(int j=0; j<=len; j++){
           fin >> AdjMatrix[i][j];
       }
   }
   fin.close();

   //Adj transpose array생성
   for(int i=0; i<=len; i++){
       for(int j=0; j<=len; j++){
           AdjMatrix_TP[i][j] = AdjMatrix[j][i];    //Adj array값을 복사, 이때 transpose를 적용시키기 위해 원래의 Adj array의 row, column의 순서를 바꾼 값으로 저장
       }
   }
   

   //Adj array 출력(확인용)
   cout << "\n*Print Adjacency Matrix*\n\n";
   for(int i=0; i<=len; i++){
       for(int j = 0; j<=len; j++){
           cout << AdjMatrix[i][j] << " ";
       }
       cout << "\n";
   }
   cout << "\n\n";

   //Adj transpose array 출력(확인용)
   cout << "\n*Print Adjacency Transpose Matrix*\n\n";
   for(int i=0; i<=len; i++){
       for(int j = 0; j<=len; j++){
           cout << AdjMatrix_TP[i][j] << " ";
       }
       cout << "\n";
   }
   cout << "\n\n";

   //Adj List, Adj Transpose List 헤더값 저장(char타입 vecter 배열의 가장 처음 값을 리스트의 헤더값으로 사용할것임)
   for(int i=1; i<=len; i++){
       AdjList[i].push_back(AdjMatrix[0][i]);
       AdjList_TP[i].push_back(AdjMatrix[0][i]);
   }

   //Adj List 생성
   for(int i=1; i<=len; i++){
       for(int j=1; j<=len; j++){
           if(AdjMatrix[i][j] == '1'){
               AdjList[i].push_back(AdjMatrix[0][j]);
           }
       }
   }

   //Adj Transpose List 생성
   for(int i=1; i<=len; i++){
       for(int j=1; j<=len; j++){
           if(AdjMatrix_TP[i][j] == '1'){
               AdjList_TP[i].push_back(AdjMatrix_TP[0][j]);
           }
       }
   }

   // 1) Print Array of adjacency list of above graph
   cout << "\n*Array of adjacency list of above graph*\n\n";
   for(int i=1; i<=len; i++){
       for(int j=0; j<AdjList[i].size(); j++){
           cout << AdjList[i][j];
           if(j < AdjList[i].size()-1){
               cout << " -> ";
           }
       }
       cout << "\n";
   }
   cout << "\n\n";

   // 2) Print Array of adjacency list of transpose graph
   cout << "\n*Array of adjacency list of transpose graph*\n\n";
   for(int i=1; i<=len; i++){
       for(int j=0; j<AdjList_TP[i].size(); j++){
           cout << AdjList_TP[i][j];
           if(j < AdjList_TP[i].size()-1){
               cout << " -> ";
           }
       }
       cout << "\n";
   }
   cout << "\n\n";
   

   return 0;

}