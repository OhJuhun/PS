#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n, m;
	long long int cards[1001];

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	sort(cards, cards + n);
	for (int i = 0; i < m; i++) {
		long long int tmp = cards[0] + cards[1];
		cards[0] = tmp;
		cards[1] = tmp;
		sort(cards, cards + n);
	}

	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += cards[i];
	}
	cout << sum << endl;

	return 0;
}