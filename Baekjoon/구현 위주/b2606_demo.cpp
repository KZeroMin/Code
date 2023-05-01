#include <iostream>
#include <vector>
using namespace std;
vector<int> node[101];
int arr[101];

void Explore(int node_num){
    arr[node_num] = 1;
    for(int i=0; i<node[node_num].size(); i++){
        Explore(node[node_num][i]);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int Computer, pair, node1, node2, count;
    count = 0;
    cin >> Computer;
    cin >> pair;

    for(int i=0; i<pair; i++){
        cin >> node1 >> node2;
        node[node1].push_back(node2);
    }

    for(int i=0; i<node[1].size(); i++){
        Explore(node[1][i]);
    }

    for(int i=0; i<101; i++){
        count += arr[i];
    }

    cout << count;

    return 0;

}