#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n, m;
vector<long long> tree[400001];
vector<int> v;

void make_tree(int idx) {
	int nidx = idx / 2;
	while (nidx >= 1) {
		int i = 0, j = 0; //left, right
		while(i < tree[nidx*2].size() && j < tree[nidx*2+1].size()) {
			if (tree[nidx * 2][i] < tree[nidx * 2 + 1][j]) {
				tree[nidx].push_back(tree[nidx * 2][i++]);
			}
			else {
				tree[nidx].push_back(tree[nidx * 2 + 1][j++]);
			}
		}
		while (i < tree[nidx * 2].size())
			tree[nidx].push_back(tree[nidx * 2][i++]);
		while (j < tree[nidx * 2 + 1].size())
			tree[nidx].push_back(tree[nidx * 2 + 1][j++]);

		nidx++;
		if (nidx == idx) idx /= 2, nidx = idx / 2;
	}
}

int ans(int node, int s,int e,int l,int r,int t) {
	if (s > r || e < l) return 0;
	if (s >= l && e <= r) {
		return tree[node].end()-upper_bound(tree[node].begin(),tree[node].end(),t);
	}

	return ans(node * 2, s, (s + e) / 2, l, r, t) +
		ans(node * 2 + 1, (s + e) / 2 + 1, e, l, r, t);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int first = log2(n);
	first = 1 << (first + 1);
	for (int i = 0; i < n; i++) {
		int r;
		cin >> r;
		tree[i + first].push_back(r);
	}
	make_tree(first);

	cin >> m;
	while (m--) {
		int i, j, t;
		cin >> i >> j >> t;
		cout << ans(1, 1, first, i, j, t) << '\n';
	}
	return 0;
}