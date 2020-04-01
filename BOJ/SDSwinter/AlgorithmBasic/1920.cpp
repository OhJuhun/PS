#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include "stdio.h"
// 탈출 치킨거리

using namespace std;

void binarySearch(vector<int> &v, int x) {
	int s = 0;
	int f = v.size() - 1;
	int mid = (s + f) / 2;
	while (s <= f) {
		mid = (s + f) / 2;
		if (v[mid] == x) {
			printf("1\n");
			return;
		}
		else if (v[mid] > x){ 
			f = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	printf("0\n");
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	vector<int> v;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int k;
		scanf("%d",&k);
		v.push_back(k);
	}
	int M;
	scanf("%d", &M);
	vector<int> f;
	for (int i = 0; i < M; i++) {
		int k;
		scanf("%d", &k);
		f.push_back(k);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < M; i++) {
		binarySearch(v,f[i]);
	}

	return 0;
}