#include <iostream>
#include <vector>
using namespace std;


bool check(vector<long long> v, long long mid, long long N) {
	long long cnt = 0;
	if (mid == 0) return true;
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i] / mid;
	}
	return cnt >= N;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long K, N;
	cin >> K >> N;
	vector<long long> v(K + 1);
	long long l = 0, H = 0, ans = 0;
	for (int i = 0; i < K; i++) {
		cin >> v[i];
		if (H < v[i]) H = v[i];
		if (l > v[i]) l = v[i];
	}


	while (l <= H) {
		long long  mid = (l + H) / 2;
		if (check(v, mid, N)) {
			if (ans < mid)
				ans = mid;
			l = mid + 1;
		}
		else {
			H = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;

}