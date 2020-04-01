#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		long long k, value;
		char cmd;
		multiset<long long> s;
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> cmd >> value;
			if (cmd == 'I')
				s.insert(value);
			else
				if (s.empty()) continue;
				else if (value == 1)
					s.erase(--s.end());
				else
					s.erase(s.begin());
		}
		if (s.empty())
			cout << "EMPTY\n";
		else
			cout << *(--s.end()) << " " << *s.begin() << '\n';
	}
	return 0;
}