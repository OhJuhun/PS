#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long evenTree[400001];
long long oddTree[400001];
long long tree[100001];
int n, m;
void make_tree(int cidx) {
	int nidx = cidx / 2;
	while (nidx >= 1) {
		evenTree[nidx] = evenTree[nidx * 2] + evenTree[nidx * 2 + 1];
		oddTree[nidx] = oddTree[nidx * 2] + oddTree[nidx * 2 + 1];
		nidx++;
		if (cidx == nidx)
			cidx /= 2, nidx = cidx / 2;
	}
}

void update(int first, int idx,int r) {
	idx = first + idx - 1;
	bool odd = false;
	if (r & 1)
		odd = true;
	while (idx >= 1) {
		if (odd) {
			evenTree[idx]--;
			oddTree[idx]++;
		}
		else {
			evenTree[idx]++;
			oddTree[idx]--;
		}
		idx /= 2;
	}
}
int answer(long long t[400001],int s,int e,int l,int r,int root) {
	if (l <= s && e <= r) {
		return t[root];
	}
	if (l > e || s > r) return 0;
	return answer(t, s, (s + e) / 2, l, r, root * 2)
		+ answer(t, (s + e) / 2 + 1, e, l, r, root * 2 + 1);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int r = log2(n);
	int first = 1 << (r+1);
	for (int i = 1; i <= n; i++) {
		cin >> tree[i];
		if (tree[i] & 1) {
			evenTree[first + i - 1] = 0;
			oddTree[first + i - 1] = 1;
		}
		else {
			evenTree[first + i - 1] = 1;
			oddTree[first + i - 1] = 0;
		}
	}

	make_tree(first);
	cin >> m;
	while (m--) {
		int cmd, l, r;
		cin >> cmd >> l >> r;
		switch (cmd) {
		case 1:
			//treel을 r로 바꾼다
			if (tree[l] %2!=r%2) {
				tree[l] = r;
				update(first, l,r);
			}
			break;
		case 2:
			//작수
			cout << answer(evenTree, 1,first,l,r,1)<<'\n';
			break;
		case 3:
			cout << answer(oddTree, 1, first, l, r, 1) << "\n";
			break;
		}
		

	}
	return 0;
}