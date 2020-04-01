#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


struct lazytree {
	long long val = 0;
	long long lazy = 0;
};
lazytree tree[2000001];

void __init__(int idx) {
	int nidx = idx / 2;
	while (nidx >= 1) {
		tree[nidx].val = tree[nidx * 2].val ^ tree[nidx * 2 + 1].val;

		nidx++;
		if (nidx == idx) idx /= 2, nidx = idx / 2;
	}
}

void lazypropagation(int r, int s, int e) {
	if (tree[r].lazy == 0) return;
	tree[r].val ^= tree[r].lazy*((e - s + 1) % 2);

	if (s != e) {
		tree[r * 2].lazy ^= tree[r].lazy;
		tree[r * 2+1].lazy ^= tree[r].lazy;
	}
	tree[r].lazy = 0;
}

void update(int r, int s, int e, int i, int j,int diff) {
	lazypropagation(r, s, e);

	if (s > j || e < i) return;
	if (s >= i && e <= j) {
		tree[r].val ^= diff * ((e - s + 1) % 2);
		if (s != e) {
			tree[r * 2].lazy ^= diff;
			tree[r * 2 + 1].lazy ^= diff;
		}
		return;
	}
	
	update(r * 2, s, (s + e) / 2, i, j, diff);
	update(r * 2 + 1, (s + e) / 2+1, e, i, j, diff);
	tree[r].val = (tree[r * 2].val^tree[r * 2+1].val);
}

long long query(int r, int s, int e, int i, int j) {
	lazypropagation(r, s, e);
	if (s > j || e < i) return 0;
	if (s >= i && e <= j)
		return tree[r].val;
	return query(r*2, s, (s + e) / 2, i, j) ^ query(r*2+1, (s + e) / 2+1, e, i, j);
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	int r = log2(n-1) + 1;
	int first = 1 << r;
	for (int i = 0; i < n; i++) {
		cin >> tree[i + first].val;
	}
	__init__(first);
	cin >> m;
	while (m--) {
		int t, a, b, c;
		cin >> t >> a >> b;
		if (a > b) swap(a, b);
		a++;
		b++;
	//	cout << a << b << endl;
		switch (t) {
		case 1:
			//update
			cin >> c;
			update(1, 1, first, a, b, c);
			break;
		case 2:
			//query
			cout << query(1, 1, first, a, b) << '\n';
			break;
		}
	/*	for (int i = 1; i < n + first; i++)
			cout << tree[i].val << " ";
		cout << endl;
		for (int i = 1; i < n + first; i++)
			cout << tree[i].lazy << " ";
		cout << endl;*/
	}
	return 0;
}