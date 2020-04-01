#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int weight;
	vector<int> v;
	int arr[9];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back(i);
	}
	int answer = 0;
	do {
		bool ans = true;
		weight = 500;
		for (int i = 0; i < v.size(); i++) {
			//arr[v[i]]만큼 하루에 증가
			weight -= k;
			weight += arr[v[i]];
		//	cout << arr[v[i]] << " ";
			if (weight < 500) {
				ans = false;
				break;
			}
		}
	//	cout << endl;
		if (ans) answer++;
	} while (next_permutation(v.begin(), v.end()));
	cout << answer << endl;
	return 0;
}