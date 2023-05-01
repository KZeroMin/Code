#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;
#define INF 1e9 // 무한대의 값으로 10억 설정


string words[31];
string AdjMatrix[31][31];   // input file로부터 생성될 Adjacency Matrix
vector<pair<int, int> > graph[31]; // 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
int Distance[31]; // 시작 노드로 부터 각 노드별 최단 거리를 저장할 배열
int start_node;  // 시작 노드 번호
int dp[31][31]; // Floyd 알고리즘를 통해 구한 matrix를 저장할 배열
int nodeNum;    // 입력받은 노드의 수


void Dijkstra(){
    priority_queue<pair<int,int>>pq; // 각 노드별 거리를 초기화 시킨 후 넣을 priority queue
    
    pq.push({0,start_node}); //시작 노드의 distance를 0으로 초기화한 후, queue에 넣음
    Distance[start_node]=0; // 시작 노드의 distance를 0으로 초기화
    
    while(!pq.empty())
    {
        int dist = -pq.top().first; //현재 노드까지의 distance
        int now = pq.top().second; // 현재 노드
        pq.pop();
        
        if(Distance[now]<dist) // 이미 최단경로를 체크한 노드인 경우 패스
            continue;
        
        // 현재 노드와 Adj 노드를 relaxation
        for(int i=0; i<graph[now].size(); i++)
        {
            int cost = dist+graph[now][i].second; // cost = 현재 노드까지의 distance + 현재 노드부터 i번째 Adj 노드까지의 distance
            if(cost<Distance[graph[now][i].first]) // Relaxation 진행
            {
                Distance[graph[now][i].first]=cost;
                pq.push(make_pair(-cost,graph[now][i].first));  // relaxation된 distance를 저장
            }
        }
    }
}

void Floyd(){
    for(int i = 1; i <= nodeNum; i++){
        for(int j = 1; j <= nodeNum; j++){
            if(AdjMatrix[i][j] == "INF"){
                dp[i][j] = INF; //  초기 Matrix에 i노드와 j노드 사이의 거리가 없다면 무한으로 초기화
            }
            else{
                dp[i][j] = stoi(AdjMatrix[i][j]);   // 초기 Matrix에 주어진 값으로 초기화
            }
        }
    }
    // Dynamic programing
    for(int k = 1; k <= nodeNum; k++){  // k : Intermediate vertices
        for(int i = 0; i <= nodeNum; i++){
            for(int j = 0; j <= nodeNum; j++){
                if(dp[i][k] + dp[k][j] < dp[i][j]){ // k를 사용할 경우
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
}

// Dijkstra 알고리즘을 사용한 결과 출력 함수
void Print_Dijkstra(int k){
    for (int i = 1; i <= k; i++)
    {
        if (Distance[i] == INF) {  // path가 존재하지 않는다면 INF로 출력
            cout << "INF" << '\n';
        }
        else {
            cout << setw(15) << Distance[i];   // path가 존재한다면 distance출력
        }
    }
}

// Floyd 알고리즘을 사용한 결과 출력 함수
void Print_Floyd(){
    for(int i = 1; i <= nodeNum; i++){
        cout << setw(15) << AdjMatrix[i][0] << "|";
        for(int j = 1; j <= nodeNum; j++){

            if(dp[i][j] == INF){
                cout << setw(15) << "INF";  // path가 존재하지 않는다면 INF로 출력
            }
            else{
                cout << setw(15) << dp[i][j];   // path가 존재한다면 distance출력
            }
        }
        cout << "\n";
    }

}

int main(){


    int k = 0;
    int i = 1;
    int j = 0;
    int weight = 0; // 노드의 weight값을 저장할 변수
    string filename("hw5_data.txt");
    string word;

    ifstream input_file(filename);

    // Adj array생성
    while (input_file >> word){
        
        if(words[0] != word){
            words[k] = word;
            AdjMatrix[0][k+1] = word;
            k += 1;
        }
        else{
            AdjMatrix[i][j] = word;
            j += 1;
            nodeNum = k;
            break;
        }
    }
    while (input_file >> word){
        AdjMatrix[i][j] = word;
        j += 1;
        if(j == k+1){
            i += 1;
            j = 0;
        }
    }

    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            if(AdjMatrix[i][j] == "0" || AdjMatrix[i][j] == "INF" || AdjMatrix[i][j] == " "){
                // do nothing
            }
            else{
                weight = stoi(AdjMatrix[i][j]); // Adj노드의 weight
                graph[i].push_back({j, weight});    // i번째 노드의 Adj노드의 인덱스와 weight값 저장
            }
        }
    }
    

    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

    fill(Distance, Distance + 31, INF);   // 초반에 전체 노드의 distancec를 무한대 값으로 초기화
    
    // Dijkstra's algorithm결과 출력
    cout << "\n*Dijkstra's algorithm result*\n\n";
    cout << setw(15) << "";
    for(int i = 1; i <= k; i++){
        cout << setw(15)  << AdjMatrix[0][i];
    }
    cout << "\n\n";
    for(start_node = 1; start_node <= k; start_node++){
        cout << setw(15) << AdjMatrix[start_node][0] << "|";
        Dijkstra();
        Print_Dijkstra(k);
        cout << "\n";
        fill(Distance, Distance + 31, INF);

    }

    cout << "\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

    //  Apply Floyd's algorithm
    cout << "\n*Floyd algorithm result*\n\n";
    cout << setw(15) << "";
    for(int i = 1; i <= k; i++){
        cout << setw(15)  << AdjMatrix[0][i];
    }
    cout << "\n\n";
    Floyd();
    Print_Floyd();
    cout << "\n";


    return 0;
}