#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;


#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define INF 987654321

const bool cmp(const string& a, const string& b) {
	return a.length() > b.length();
}
struct Trie {
	bool terminal;
	Trie* next[10]; //a~z
	Trie() : terminal(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 10; i++)
			if(next[i]) delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0') terminal = true;
		else {
			int cur = *key - '0';
			if (next[cur] == NULL) next[cur] = new Trie();
			next[cur]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == NULL) return true;
		int cur = *key - '0';
		if (next[cur] == 0) return  false;
		return next[cur]->find(key + 1);
	}
};

int main() {
	PREPROCESS;
	int t;
	cin >> t;
	while (t--) {
		Trie *root = new Trie;
		int n;
		cin >> n;
		string str[10000];
		for (int i = 0; i < n; i++)
			cin >> str[i];
		int r = 0;
		bool flag = false;
		sort(str, str + n, cmp);
		for (int i = 0; i < n; i++) {
			const char* c = str[i].c_str();
			if (root->find(c)) {
				flag = true;
				break;
			}
			else {
				root->insert(c);
			}
		}
		cout << (flag ? "NO\n" : "YES\n");
	}
	return 0;
}