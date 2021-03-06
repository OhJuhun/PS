#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long tree[400001];
int n, m;

void make_tree(int cidx) { //최소값 트리로 구성
	int nidx = cidx / 2;
	while (nidx >= 1) {
		tree[nidx++] = tree[nidx * 2] != 0 && tree[nidx * 2 + 1] != 0
			? min(tree[nidx * 2], tree[nidx * 2 + 1]) : tree[nidx * 2] + tree[nidx * 2+1];
		
		if (nidx == cidx) {
			cidx /= 2;
			nidx = cidx / 2;
		}
	}
}

void update(int first,int i, int v) {
	i = first + i-1;
	tree[i] = v;
	i /= 2;
	while (i >= 1) {
		tree[i] = tree[i * 2] != 0 && tree[i * 2 + 1] != 0 ?
			min(tree[i * 2], tree[i * 2 + 1]) : tree[i * 2] + tree[i * 2 + 1];
		i /= 2;
	}
}

int findMin(int r, int m, int n, int s, int e) {
	if (s <= m && n  <= e && tree[r] != 0) return tree[r];

	if (e < m || n < s) return 1000000001;

	return min(findMin(2 * r, m, (n + m) / 2, s, e), findMin(2 * r + 1, (n + m) / 2 + 1, n, s, e));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int r = log2(n);
	int first = 1 << (r+1);
	for (int i = 0; i < n; i++)
		cin >> tree[first + i];
	make_tree(first);
	//트리로 만들기
	cin >> m;
	while (m--) {
		int cmd,i, j;
		cin >>cmd>> i >> j;
		switch (cmd) {
		case 1:
			update(first, i, j);
			break;
		case 2:
			cout << findMin(1,1,first,i,j) << '\n';
			break;
		}
	}
	return 0;
}