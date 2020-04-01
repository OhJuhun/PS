#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct st {
	long long val, lazy=0;
};
st tree[4000002];

int n, m,k;
void make_tree(int cidx) {
	int nidx = cidx / 2;
	while (nidx >= 1) {
		tree[nidx].val = tree[nidx * 2].val + tree[nidx * 2 + 1].val;
		nidx++;
		if (nidx == cidx) cidx /= 2, nidx = cidx / 2;
	}
}

void update(int root,int s,int e,long long plus,int l, int r) { //Lazy Propagation
	if (tree[root].lazy != 0) {
		//이전 lazy가 있을 경우
		tree[root].val += (e - s + 1)*tree[root].lazy;//노드의 수만큼 더해줌
		if (s != e) {
			tree[root * 2].lazy += tree[root].lazy;
			tree[root * 2 + 1].lazy += tree[root].lazy; //lazy를 다음 level로 넘김
		}
		tree[root].lazy = 0;
	}

	if (r<s || l > e) return; //범위를 벗어난 경우

	if (l <= s && e <= r) { //대표 구간에 포함됨
		tree[root].val += (e - s + 1)*plus; //대표값에 노드 수만큼 +
		if (s != e) {
			tree[root * 2].lazy += plus;
			tree[root * 2+1].lazy += plus;
		}
		return;
	}
	update(root * 2, s, (s + e) / 2, plus, l, r);
	update(root * 2 + 1, (s + e) / 2 + 1, e, plus, l, r);
	
	tree[root].val = tree[root * 2].val + tree[root * 2 + 1].val;
}
long long answer(int s,int e,int l,int r,int root) {

	if (tree[root].lazy != 0) {
		tree[root].val += (e - s + 1)*tree[root].lazy;
		if (s != e) {
			tree[root * 2].lazy += tree[root].lazy;
			tree[root * 2 + 1].lazy += tree[root].lazy;
		}
		tree[root].lazy = 0;
	}
	if (l > e || s > r) return 0;
	if (l <= s && e <= r) {
		return tree[root].val;
	}
	return answer(s, (s + e) / 2, l, r, root * 2)
		+ answer((s + e) / 2 + 1, e, l, r, root * 2 + 1);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n>>m>>k;
	int r = log2(n);
	int first = 1 << (r+1);
	for (int i = 0; i < n; i++) {
		cin >> tree[first + i].val;
	}

	make_tree(first);
	int t = m + k;
	while (t--) {
		int a, b, c;
		long long d;
		cin >> a;
		switch (a) {
		case 1:
			cin >> b >> c >> d;
			update(1,1,first,d,b,c);
			break;
		case 2:
			cin >> b >> c;
			cout << answer(1,first,b,c,1) << '\n';
			break;
		}
	}
	return 0;
}