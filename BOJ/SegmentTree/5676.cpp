#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define MAX 987654321
int tree[700001];
int n, k;

void make_tree(int idx) {
	int nidx = idx / 2;
	while (nidx >= 1) {
		if (tree[nidx * 2] != MAX && tree[nidx * 2 + 1] != MAX) {
			//둘 다 값이 있는 경우
			tree[nidx] = tree[nidx * 2] * tree[nidx * 2 + 1];
		}
		else if (tree[nidx * 2] == MAX && tree[nidx * 2 + 1] == MAX) {
			//둘 다 값이 없는 ㄱㅇ우
			tree[nidx] = MAX;
		}
		else if (tree[nidx * 2] != MAX && tree[nidx * 2 + 1] == MAX) {
			//한 쪽만 값이 잇는 경우
			tree[nidx] = tree[nidx * 2];
		}
		nidx++;
		if (nidx == idx) idx /= 2, nidx = idx / 2;
	}
}

void update(int first,int i,int v) {
	//바꾸려는 값이 같을 부호를 가지면 그대로 두고 아니면 변경한다
	if (tree[first + i-1] == v) {
		return;
	}
	tree[first + i-1] = v;
	int nidx = (first + i-1) / 2;
	while (nidx >= 1) {
		if (tree[nidx * 2] != MAX && tree[nidx * 2 + 1] != MAX) {
			//둘 다 값이 있는 경우
			tree[nidx] = tree[nidx * 2] * tree[nidx * 2 + 1];
		}
		else if (tree[nidx * 2] == MAX && tree[nidx * 2 + 1] == MAX) {
			//둘 다 값이 없는 경우
			tree[nidx] = MAX;
		}
		else if (tree[nidx * 2] != MAX && tree[nidx * 2 + 1] == MAX) {
			//한 쪽만 값이 잇는 경우
			tree[nidx] = tree[nidx * 2];
		}
		nidx /= 2;
	}
}

int query(int r, int s, int e, int i, int j) {
	if (s > j || e < i) return 1;
	if (s >= i && e <= j) return tree[r];
	return query(r * 2, s, (s + e) / 2, i, j) * 
		query(r * 2 + 1, (s + e) / 2 + 1, e, i, j);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T = 2;
	while (cin >> n >> k) {
		int r = log2(n - 1);
		int first = 1 << (r + 1);
		memset(tree, MAX, first * 2);
		for (int i = 0; i < n; i++) {
			cin >> tree[i + first];
			tree[i + first] = tree[i + first] == 0 ? 0 : tree[i + first] > 0 ? 1 : -1;
		}
		for (int i = n + first; i < first * 2; i++)
			tree[i] = MAX;
		make_tree(first);
		string answer = "";
		while (k--) {
			char cmd;
			int i, j;
			cin >> cmd >> i >> j;
			switch (cmd) {
			case 'C':
				//CHANGE
				j = j > 0 ? 1 : j < 0 ? -1 : 0;
				update(first, i, j);
				break;
			case 'P':
				//PLUS 출력 
				int q = query(1, 1, first, i, j);
				if (q == 1)
					answer += "+";
				else if (q == 0)
					answer += "0";
				else
					answer += "-";
				break;
			}
		}
		cout << answer << endl;
	}
	return 0;
}