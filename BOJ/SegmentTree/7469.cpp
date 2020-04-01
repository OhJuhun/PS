#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <set>
using namespace std;

vector<int> tree[400001];
void make_tree(int idx) {
	int nidx = idx / 2;
	while (nidx >= 1) {
		int i = 0, j = 0;
		while (i < tree[nidx * 2].size() && j < tree[nidx * 2 + 1].size()) {
			if (tree[nidx * 2][i] < tree[nidx * 2 + 1][j])
				tree[nidx].push_back(tree[nidx * 2][i++]);
			else
				tree[nidx].push_back(tree[nidx * 2 + 1][j++]);
		}
		while (tree[nidx * 2].size() > i)
			tree[nidx].push_back(tree[nidx * 2][i++]);
		while (tree[nidx * 2 + 1].size() > j)
			tree[nidx].push_back(tree[nidx * 2 + 1][j++]);
		nidx++;
		if (nidx == idx) idx /= 2, nidx = idx / 2;
	}
}

int Q(int s,int e,int i,int j,int r,int k) {
	if (s > j || e < i) return 0;
	
	if (s >= i && e <= j) {
		return upper_bound(tree[r].begin(),tree[r].end(),k)-tree[r].begin();
	}
	return Q(s, (s + e) / 2, i, j, r * 2,k) +
	Q((s + e) / 2 + 1, e, i, j, r * 2 + 1,k);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int first = 1 << ((int)log2(n))+1;
	
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		tree[first + i].push_back(r);
	}
	make_tree(first);
	while (m--) {
		int i, j, k;
		cin >> i >> j >> k;
		int l = -(1e9), r = 1e9;
		while (l <= r) {
			int m = (l + r) / 2;
			if (Q(1, first, i, j, 1, m) < k) l = m + 1;
			else r = m - 1;
		}
		cout << l << '\n';

	}
	return 0;
}