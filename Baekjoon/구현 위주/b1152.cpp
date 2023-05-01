#include<iostream>
#include<sstream>

using namespace std;

int main()
{
    string str;
    int count = 0;
    getline(cin, str);

    stringstream ss(str);
    ss.str(str);

    string word;
    while(ss >> word){
        count++;
    }

    cout << count;

    return 0;
}