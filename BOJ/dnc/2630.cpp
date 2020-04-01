#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[129][129];
int answ, ansb;
void solve(int rs, int cs, int re, int ce) {
	int check = arr[rs][cs];

	for (int i = rs; i < re; i++) {
		for (int j = cs; j < ce; j++) {
			if (check==0 && arr[i][j]) {
				check = 2;
			}
			else if (check==1 && !arr[i][j]) {
				check = 2;
			}
			if (check == 2) {
				solve(rs, cs, (rs + re) / 2, (cs + ce) / 2);
				solve((rs + re) / 2, (cs + ce) / 2, re, ce);
				solve((rs + re) / 2, cs, re, (cs + ce) / 2);
				solve(rs, (cs + ce) / 2, (rs + re) / 2, ce);
				return;
			}
		}
	}
	if (check==1) ansb++;
	else if (check == 0) answ++;
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	}
	solve(0, 0, n, n);
	cout << answ << endl << ansb << endl;
	return 0;
}