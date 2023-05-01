#include <iostream>
using namespace std;

int main() {
	int x, y, w, h;
	int short_way;
	cin >> x >> y >> w >> h;

	short_way = x;
	if (w - x < short_way)
		short_way = w - x;
	if (y < short_way)
		short_way = y;
	if (h - y < short_way)
		short_way = h - y;

	cout << short_way << '\n';
}