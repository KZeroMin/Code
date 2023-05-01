#include <iostream>
#include <algorithm>
using namespace std;

bool Compare(string a, string b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    else{
        return a < b;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Num_of_word;
    string word;

    cin >> Num_of_word;
    string word_list[Num_of_word];

    for(int i = 0; i< Num_of_word; i++){
        cin >> word_list[i];
    }

    sort(word_list, word_list+Num_of_word, Compare);

    for(int i = 0; i< Num_of_word; i++){
        if(i != (Num_of_word -  1) && word_list[i] == word_list[i+1]){
            continue;
        }
        cout << word_list[i] << endl;
    }

    return 0;
}