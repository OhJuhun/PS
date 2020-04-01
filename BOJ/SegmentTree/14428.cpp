#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


long long tree[400010];
long long arr[100001];
int n, m;
void make_tree(int cidx) {
	int nidx = cidx / 2;
	while (nidx >= 1) {
		int lidx = tree[nidx * 2];
		int ridx = tree[nidx * 2 + 1];
		if (lidx != 0 && ridx != 0) {
			//둘 다 빈 곳이 아닐 때
			tree[nidx] = arr[lidx] <= arr[ridx] ? lidx : ridx;
		}
		else if (lidx != 0 && ridx == 0) {
			tree[nidx] = lidx;
		}
		else if (lidx == 0 && ridx != 0) {
			tree[nidx] = ridx;
		}
		nidx++;
		if (nidx == cidx) cidx /= 2, nidx = cidx / 2;
	}
}

void update(int i) {
	while (i >= 1) {
		int lidx = tree[i * 2];
		int ridx = tree[i * 2 + 1];
		if (lidx != 0 && ridx != 0) {
			//둘 다 빈 곳이 아닐 때
			tree[i] = arr[lidx] <= arr[ridx] ? lidx : ridx;
		}
		else if (lidx != 0 && ridx == 0) {
			tree[i] = lidx;
		}
		else if (lidx == 0 && ridx != 0) {
			tree[i] = ridx;
		}
		i /= 2;
	}
}
int ans(int root, int s,int e,int l,int r) {
	if (s > r || e < l) {
		return -1;
	}
	if (l <= s && e <= r) {
		return tree[root];
	}
	int ll = ans(root * 2, s, (s + e) / 2, l, r);
	int rr = ans(root * 2+1, (s + e) / 2 + 1, e, l, r);
	if (ll == -1) return rr;
	if (rr == -1) return ll;
	return arr[ll] <= arr[rr] ? ll : rr;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int r = log2(n);
	int first = 1 << (r+1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
		tree[first + i] = i + 1;
	}
	make_tree(first);
	cin >> m;
	while (m--) {
		int cmd, i;
		long long j;
		cin >> cmd >> i >> j;
		switch (cmd) {
		case 1:
			arr[i] = j;
			update((first+i-1)/2);
			break;
		case 2:
			cout << ans(1, 1, first, i, j)<<'\n';
			break;
		}
	}
	return 0;
}