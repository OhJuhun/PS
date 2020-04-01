#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

pair<long long, long long> ptree[400001];
long long tree[100001];
long long ff, ss;
void __init__(int idx) {
	int nidx = idx / 2;
	while (nidx >= 1) {
		//first는 4개중 가장 큰 것이므로 큰거 두개중에만 비교하면 됨
		if (ptree[nidx * 2].first > ptree[nidx * 2 + 1].first) {
			ptree[nidx].first = ptree[nidx * 2].first;
			ptree[nidx].second = max(ptree[nidx * 2 + 1].first, ptree[nidx * 2].second);
		}
		else {
			ptree[nidx].first = ptree[nidx * 2+1].first;
			ptree[nidx].second = max(ptree[nidx * 2].first, ptree[nidx * 2 + 1].second);
		}
		nidx++;
		if (nidx == idx) idx /= 2, nidx = idx / 2;
	}
}

void update(int first, int i, int v) {
	int idx = first + i - 1;
	ptree[idx].first = v;
	int nidx = idx / 2;
	while (nidx >= 1) {
		//first는 4개중 가장 큰 것이므로 큰거 두개중에만 비교하면 됨
		if (ptree[nidx * 2].first > ptree[nidx * 2 + 1].first) {
			ptree[nidx].first = ptree[nidx * 2].first;
			ptree[nidx].second = max(ptree[nidx * 2 + 1].first, ptree[nidx * 2].second);
		}
		else {
			ptree[nidx].first = ptree[nidx * 2 + 1].first;
			ptree[nidx].second = max(ptree[nidx * 2].first, ptree[nidx * 2 + 1].second);
		}
		nidx /= 2;
	}
}

void query(int r,int s,int e,int i, int j) {
	if (s > j || e < i)  return;
	else if (s >= i && e <= j) {
		vector<int> v;
		v.push_back(ff);
		v.push_back(ss);
		v.push_back(ptree[r].first);
		v.push_back(ptree[r].second);
		sort(v.begin(), v.end());
		ff = v[3], ss = v[2];
		return;
	}
	query(r * 2, s, (s + e) / 2, i, j);
	query(r * 2 + 1, (s + e) / 2 + 1, e, i, j);
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n;
	int r = log2(n - 1) + 1;
	int first = 1 << r;
	for (int i = 0; i < n; i++) {
		cin >> ptree[i+first].first;
		ptree[i+first].second = 0;
	}
	__init__(first);

	cin >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		switch (a) {
		case 1:
			update(first, b, c);
			break;
		case 2:
			query(1, 1, first, b, c);
			cout << ff+ss << '\n';
			ff = 0, ss = 0;
			break;
		}
	}
	return 0;
}