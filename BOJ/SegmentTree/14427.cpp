#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long tree[400001];
int n, m;

void make_tree(int cidx) { //최소트리로 관리하면됨
	int nidx = cidx / 2;
	while (nidx >= 1) {
		if (tree[nidx * 2] == 0 && tree[nidx * 2 + 1] == 0)
			tree[nidx] = 0;
		else if (tree[nidx * 2] == 0 && tree[nidx * 2 + 1] != 0)
			tree[nidx] = tree[nidx * 2 + 1];
		else if (tree[nidx * 2] != 0 && tree[nidx * 2 + 1] == 0)
			tree[nidx] = tree[nidx * 2];
		else
			tree[nidx] = min(tree[nidx * 2], tree[nidx * 2 + 1]);
		nidx++;
		if (nidx == cidx) {
			cidx /= 2;
			nidx = cidx / 2;
		}
	}
}

void update(int first, int idx) {
	int nidx = first + idx-1;
	nidx /= 2;
	while (nidx >= 1) {
		if (tree[nidx * 2] == 0 && tree[nidx * 2 + 1] == 0) {
			tree[nidx] = 0;
		}
		else if (tree[nidx * 2] == 0 && tree[nidx * 2 + 1] != 0) {
			tree[nidx] = tree[nidx * 2 + 1];
		}
		else if (tree[nidx * 2] != 0 && tree[nidx * 2 + 1] == 0) {
			tree[nidx] = tree[nidx * 2];
		}
		else
			tree[nidx] = min(tree[nidx * 2], tree[nidx * 2 + 1]);
		nidx /= 2;
	}
}

int findMin(int r,int first) {
	while (r < first) {
		if (tree[r] == tree[r * 2]) {
			r = r * 2;
		}
		else {
			r = r * 2 + 1;
		}
	}
	return r-first+1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int r = log2(n);
	int first = 1<<(r + 1);
	
	for (int i = 0; i < n; i++)
		cin >> tree[i + first];
	make_tree(first);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 2) {
			cout << findMin(1,first) << '\n';
		}
		else {
			int idx, v;
			cin >> idx >> v;
			tree[idx + first-1] = v;
			update(first, idx);
		}


	}
	return 0;
}