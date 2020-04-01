#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
long long mintree[400001];


void make_minTree(int cidx) {
	int nidx = cidx / 2;
	while (nidx >= 1) {
		if (mintree[nidx * 2] != 0 && mintree[nidx * 2 + 1] != 0)
			mintree[nidx] = min(mintree[nidx * 2], mintree[nidx * 2 + 1]);
		else if (mintree[nidx * 2] == 0 && mintree[nidx * 2 + 1] != 0)
			mintree[nidx] = mintree[nidx * 2 + 1];
		else if (mintree[nidx * 2] != 0 && mintree[nidx * 2 + 1] == 0)
			mintree[nidx] = mintree[nidx * 2];
		else
			mintree[nidx] = 987654321;

		nidx++;
		
		if (nidx == cidx) {
			nidx /= 4;
			cidx /= 2;
		}
	}
}

int findMin(int r, int m,int n,int s,int e) {
	if (s <= m && n <= e && mintree[r]!=0) return mintree[r];
	
	if (e < m || n < s) return 1000000001;
	
	return min(findMin(2 * r, m, (n + m) / 2, s, e),findMin(2 * r + 1, (n + m) / 2 + 1, n, s, e));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int r = log2(n)+1;
	int startidx = 1 << r;
	
	for (int i = 0; i < 1 << (r + 1); i++) {
		mintree[i] = 987654321;
	}
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		mintree[startidx + i] = k;
	}
	make_minTree(startidx);
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		cout << findMin(1, 1, startidx, s, e) << "\n";
	}
	return 0;
}