#include <iostream>
using namespace std;
int input[10];

int main()
{
    bool asc = true;
	bool des = true;

	for (int i = 1; i <= 8; i++){
        cin >> input[i];
    }
    
	for (int i = 1; i <= 8; i++) {
		if (input[i] != i) {
			asc = false;
			break;
		}
	}

	for (int i = 1; i <= 8; i++) {
		if (input[i] != 9 - i) {
			des = false;
			break;
		}
	}
	if (asc) cout << "ascending";
	else if (des) cout << "descending";
	else cout << "mixed";
}