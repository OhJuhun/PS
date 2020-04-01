#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n, m, k;
#define DIV 1000000007

long long tree[4000001];

void make_tree(int cidx) {
	int nidx = cidx / 2;
	while (nidx >= 1) {
		tree[nidx] = (tree[nidx*2]*tree[nidx*2+1]) %DIV;
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
		tree[i] = (tree[i * 2] * tree[i * 2 + 1])%DIV;
	}
	_update(i / 2, v, false);
}
long long ans(int root, int s,int e,int l,int r) {
	if (s > r || e < l) return 1;
	if (l <= s && r >= e) return tree[root];
	return (ans(root * 2, s, (s + e) / 2, l, r) 
		* ans(root * 2 + 1, (s + e) / 2 + 1, e, l, r))%DIV;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	int r = log2(n);
	int first = 1 << (r+1);
	for (int i = 0; i < n; i++) {
		cin >> tree[first + i];
	}
	for (int i = first + n; i < 1 << (r + 2);i++) {
		tree[i] = 1;
	}
	make_tree(first);
	int t = m + k;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		switch (a) {
		case 1:
			_update(b + first - 1, c, true);
			break;
		case 2:
			cout << ans(1, 1, first, b, c) << '\n';
			break;
		}
	}
	return 0;
}