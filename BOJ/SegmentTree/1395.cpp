#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


struct lazytree {
	int val = 0;
	int lazy = 0;
};
lazytree tree[400001];

void lazypropagation(int r, int s, int e) {
	if (tree[r].lazy == 0) return; //전파할 것이 없을 경우
	
	int m = (s + e) / 2;
	//레이지가 있는 경우 다음 노드에 넘겨준다
	if (s != e) {
		tree[r * 2].lazy = (m - s + 1) - tree[r * 2].lazy;
		tree[r * 2 + 1].lazy = (e - m) - tree[r * 2 + 1].lazy;
	}
	tree[r].lazy = 0;
	tree[r].val = (e - s + 1) - tree[r].val;
}

void update(int r, int s, int e, int i, int j) {
	
	lazypropagation(r, s, e);
	if (s > j || e < i) return;
	if (s >= i && e <= j) {
		//모두 포함하고 있는 노드라면 lazy를 증가시킴
		tree[r].lazy = (e - s + 1) - tree[r].lazy;
		//if (s != e) {
			//terminal node가 아닌 경우
			int m = (s + e) / 2;
			lazypropagation(r, s, e);
		//}
		return;
	}
	update(r * 2, s, (s + e) / 2, i, j);
	update(r * 2 + 1, (s + e) / 2 + 1, e, i, j);
	tree[r].val = tree[r * 2].val + tree[r * 2 + 1].val;
}

int query(int r, int s, int e, int i, int j) {
	lazypropagation(r, s, e);
	if (s > j || e < i) return 0;
	if (s >= i && e <= j) {
		return tree[r].val;
	}
	return query(r * 2, s, (s + e) / 2, i, j) + query(r * 2 + 1, (s + e) / 2+1, e, i, j);
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int r = log2(n-1) + 1;
	int first = 1 << r;
	while (m--) {
		int o, s, t;
		cin >> o >> s >> t;
		switch (o) {
		case 0:
			update(1, 1, first, s, t);
			break;
		case 1:
			cout << query(1, 1, first, s, t) << '\n';
			break;
		}
	}
	return 0;
}