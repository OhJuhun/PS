#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


bool check(vector<long long> v,long long mid,int M) {
	long long ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if(v[i]-mid>0)
			ans += v[i] - mid;
	} //자른 크기
	return ans >= M;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M; //M은 target
	vector<long long> v(N + 1);
	long long l = 0,h=0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] > h) h = v[i];
	}
	long long ans = 0;
	while (h >= l) {
		int mid = (h + l) / 2; 
		if (check(v,mid,M)) {
			if (mid > ans)
				ans = mid;
			l = mid + 1;
		}
		else {
			h = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;

}