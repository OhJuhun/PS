#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define MAX 987654321
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
int J, A;
char arr[1000001];
int main() {
	PREPROCESS;
	cin >> J >> A;
	for (int i = 1; i <= J; i++) {
		char j;
		cin >> j;
		arr[i] = j;
	}
	int ans = 0;
	for (int i = 0; i < A; i++) {
		char j;
		int num;
		cin >> j >> num;
		if (arr[num]=='a') {
			continue;
		}
		else {
			if (j == 'S') {
				if (arr[num] == 'S' || arr[num]=='M' || arr[num]=='L') {
					ans++;
					arr[num] = 'a';
				}
			}
			else if (j == 'M') {
				if (arr[num] == 'M' || arr[num]=='L') {
					ans++;
					arr[num] = 'a';
				}
			}
			else if (j == 'L') {
				if (arr[num] == 'L') {
					ans++;
					arr[num] = 'a';
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}