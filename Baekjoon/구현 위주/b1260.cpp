#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> dfs_t[1001];

int main(){
    int N, M ,V;    // node, edge, start node
    int node1, node2;
    cin >> N >> M >> V;

    for(int i=1; i<= M; i++){   // ㅇㄷ 수 만큼 등록
        cin >> node1 >> node2;
        dfs_t[node1].push_back(node2);
        dfs_t[node2].push_back(node1);
    }

    

}