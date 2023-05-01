#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(int start, vector<int> graph[], bool check[]){
    check[start] = true;

    for(int i=0; i<graph[start].size(); i++){
        int next = graph[start][i];
        if(check[next] == false){
            DFS(next, graph, check);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int Computer, pair, node1, node2, count;
    count = 0;
    cin >> Computer;
    cin >> pair;

    vector<int> graph[Computer+1];
    bool check[Computer+1];
    fill(check, check+Computer+1, false);

    for(int i=0; i<pair; i++){
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    DFS(1, graph, check);
    for(int i=0; i<Computer+1; i++){
        if(check[i] == true){
            count +=1;
        }
    }
    cout << count-1;

    return 0;

}