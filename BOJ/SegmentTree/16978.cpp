#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct update_query {
	int i;
	int v;
};

struct sum_query{
	int k, i, j,order;
};

const bool cmp(sum_query a, sum_query b) {
	return a.k < b.k;
}

int n, m;

long long tree[400001];
vector<update_query> uqueries;
vector<sum_query> squeries;
long long answers[100001];

void make_tree(int cidx) {
	int nidx = cidx / 2;
	while (nidx >= 1) {
		tree[nidx] = tree[nidx * 2] + tree[nidx * 2 + 1];
		nidx++;
		if (nidx == cidx) cidx /= 2, nidx = cidx / 2;
	}
}

void _update(int i,int v, bool start) { //Lazy 필요 x
	if (i == 0) return;
	if (start) {
		tree[i] = v;
	}
	else {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
	_update(i / 2, v, false);
}
long long ans(int root, int s,int e,int l,int r) {
	if (s > r || e < l) return 0;
	if (l <= s && r >= e) return tree[root];
	return ans(root * 2, s, (s + e) / 2, l, r) 
		+ ans(root * 2 + 1, (s + e) / 2 + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int r = log2(n);
	int first = 1 << (r+1);
	for (int i = 0; i < n; i++) {
		cin >> tree[first + i];
	}
	make_tree(first);

	int m;
	cin >> m;
	while (m--) {
		int cmd;
		cin >> cmd;
		switch (cmd) {
		case 1:
			update_query utmp;
			cin >> utmp.i >> utmp.v;
			uqueries.push_back(utmp);
			break;
		case 2:
			sum_query stmp;
			cin >> stmp.k >> stmp.i >> stmp.j;
			stmp.order = squeries.size();
			squeries.push_back(stmp);
			break;
		}
	}
	sort(squeries.begin(), squeries.end(), cmp);

	int idx = 0; //현재 진행한 uquery
	for (sum_query squery : squeries) {
		while (idx < squery.k) {
			int i = first + uqueries[idx].i - 1;
			int v = uqueries[idx].v;
			_update(i,v,true);
			idx++;
		}
		answers[squery.order] = ans(1, 1, first, squery.i, squery.j);
	}

	for (int i = 0; i < squeries.size(); i++) {
		cout << answers[i] << '\n';
	}
	return 0;
}