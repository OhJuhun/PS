#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n, m;

long long tree[4000001];

void make_tree(int cidx) {
	int nidx = cidx / 2;
	while (nidx >= 1) {
		tree[nidx] = tree[nidx*2]+tree[nidx*2+1];
		nidx++;
		if (nidx == cidx) cidx /= 2, nidx = cidx / 2;
	}
}

void _update(int i,int v, bool start) { //Lazy 필요 x
	if (i == 0) return;
	if (start) {
		tree[i] = v;
	}
	else {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	_update(i / 2, v, false);
}
long long ans(int root, int s,int e,int l,int r) {
	if (s > r || e < l) return 0;
	if (l <= s && r >= e) return tree[root];
	return ans(root * 2, s, (s + e) / 2, l, r) 
		+ ans(root * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int r = log2(n);
	int first = 1 << (r+1);
//	make_tree(first);

	while (m--) {
		int c,i, j;
		cin >>c>> i>>j;
		switch (c) {
		case 0:
			if (i > j) swap(i, j);
			cout << ans(1, 1, first, i, j)<<'\n';
			break;
		case 1:
			_update(first + i - 1, j, true);
			break;
		}
	}
	return 0;
}