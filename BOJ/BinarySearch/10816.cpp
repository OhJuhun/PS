#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int n, m;

int lower(int target) {
	int l = 0, h = n - 1;
	while (h > l) {
		int mid = (l + h) / 2;
		if (arr[mid] >= target)
			h = mid;
		else
			l = mid + 1;
	}
	return h;
	
}
int upper(int target) {
	int l = 0, h = n - 1;
	while (l < h) {
		int mid = (l + h) / 2;
		if (arr[mid] > target)
			h = mid ;
		else
			l = mid+1;
	}
	return h;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	
	cin >> m;
	while (m--) {
		int v;
		cin >> v;
		int l = lower(v);
		int h = upper(v);
		if (h == n - 1 && arr[n - 1] == v)
			h++;
		cout << h - l << " ";
	}
	return 0;
}