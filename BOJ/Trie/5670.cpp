#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;


#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define INF 987654321

struct Trie {
	bool terminal;
	int len;
	map<char,Trie*> node;
	Trie() : terminal(false), len(0){
	//	memset(node, 0, sizeof(node));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			delete node[i];
	}

	void insert(const char* key) {
		if (*key == '\0') {
			terminal = true;
		}
		else {
			int idx = *key - 'a';
			if (node[idx] == NULL) node[idx] = new Trie(), len++;
			node[idx]->insert(key + 1);
		}
	}
	int search(const char* key,bool first,int ans) {
		if (*key == '\0') return ans;
		if (first) ans++;
		else if (terminal ||len>1) ans++;

		int idx = *key - 'a';
		return node[idx]->search(key + 1,false,ans);
	}
};

void input(int n) {
	Trie* root = new Trie();
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		const char* key = str.c_str();
		root->insert(key);
		v.push_back(str);
	}
	int ans = 0;
	for (string s : v) {
		const char* key = s.c_str();
		ans += root->search(key,true,0);
	}
	printf("%.2f\n", (float)ans / (float)n);
}
int main() {
	PREPROCESS;
	int n;
	while (cin>>n) input(n);
	return 0;
}