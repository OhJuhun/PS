#include <iostream>
#include <cmath>
using namespace std;

#define MAX 987654321
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)

struct node {
	long long val;
	long long lazy = 0;
};
int N, M;
node tree[400001];

void make_tree(int idx) {
	int nidx = idx / 2;
	while (nidx >= 1) {
		tree[nidx].val = tree[nidx * 2].val + tree[nidx * 2 + 1].val;
		nidx++;
		if (nidx == idx)
			idx /= 2, nidx = idx / 2;
	}
}


void lazypropagate(int h,int s,int e) {
	if (tree[h].lazy == 0) return;
	tree[h].val += (e - s + 1)*tree[h].lazy;
	if (s != e) {
		tree[h * 2].lazy += tree[h].lazy;
		tree[h * 2 + 1].lazy += tree[h].lazy;
	}
	tree[h].lazy = 0;
}
void update(int h, int s, int e, int l, int r, int x) {
	//lazyPropagate
	lazypropagate(h, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		tree[h].val += (e - s + 1)*x;
		if (s != e) {
			tree[h * 2].lazy += x;
			tree[h * 2 + 1].lazy += x;
		}
		return;
	}
	update(h * 2, s, (s + e) / 2, l, r, x);
	update(h * 2 + 1, (s + e) / 2 + 1, e, l, r, x);
	tree[h].val = tree[h * 2].val + tree[h * 2 + 1].val;
}

long long query(int h, int s, int e, int l, int r) {
	lazypropagate(h, s, e);

	if (s > r || e < l) return 0;
	if (s >= l && e <= r) return tree[h].val;
	
	return query(h * 2, s, (s + e) / 2, l, r) + query(h * 2 + 1, (s + e) / 2 + 1, e, l, r);
	//한쪽으로만 가면되느네
}
int main() {
	PREPROCESS;
	cin >> N;
	int r = log2(N);
	int first = 1 << (r + 1);

	for (int i = 0; i < N; i++)
		cin >> tree[i+first].val;
	cin >> M;
	while (M--) {
		int cmd, i, j, k;
		cin >> cmd;
		switch (cmd) {
		case 1:
			cin >> i >> j >> k;
			update(1, 1, first, i, j, k);
			break;
		case 2:
			cin >> k;
			cout << query(1, 1, first, k, k)<<'\n';
			break;
		}
	}
	return 0;
}