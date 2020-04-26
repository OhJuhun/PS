#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int main() {
	PREPROCESS;
	int N;
	cin >> N;
	set<int> v;
	int arr[1000001];
	for (int i = 0; i < N; i++) {
		cin >> arr[i + 1];
		v.insert(arr[i+1]);
	}
	vector<int> vv;
	for (int i : v)
		vv.push_back(i);
	sort(vv.begin(), vv.end());
	for (int i = 1; i <= N; i++) {
		cout<<lower_bound(vv.begin(), vv.end(), arr[i])-vv.begin()<<" ";
	}
	return 0;
}