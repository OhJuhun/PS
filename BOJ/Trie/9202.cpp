#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define INF 987654321

struct Trie {
	bool terminal;
	Trie* node[26];
	Trie() : terminal(false) {
		memset(node, 0, sizeof(node));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			delete node[i];
	}
	void insert(const char* key) {
		if (*key == '\0') {
			terminal = true;
			return;
		}
		int idx = *key - 'A';
		if (node[idx] == NULL) node[idx] = new Trie();
		node[idx]->insert(key + 1);
	}

	bool find(const char* key) {
		if (*key == NULL) return true;
		int idx = *key - 'A';
		if (node[idx] == 0) return false;
		return node[idx]->find(key + 1);
	}

};

Trie* root[9];
char arr[4][4];
set<string> answer;
int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{-1,-1},{1,1},{1,-1},{-1,1} };
bool visit[4][4];

void dfs(int r, int c, int count, string word) {
	if (r<0 || c<0 || r>3 || c>3 || visit[r][c]) return;
	if (count > 8) {
		return;
	}
	visit[r][c] = true;
	word += arr[r][c];
	const char* w = word.c_str();
	if (root[word.length()] != NULL && root[word.length()]->find(w)) answer.insert(word);
	for (int i = 0; i < 8; i++) {
		dfs(r + dir[i][0], c + dir[i][1], count + 1,word);
	}
	visit[r][c] = false;
}
void solve() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dfs(i, j, 1,"");
		}
	}
	int longest = 0;
	string lstr="";
	int score = 0;
	for (auto ans : answer) {
		lstr = lstr.length() < ans.length() ? ans : lstr;
		score += ans.length() == 8 ? 11 : ans.length() == 7 ? 5 : ans.length() == 6 ? 3 :
			ans.length() == 5 ? 2 : ans.length() == 3 || ans.length() == 4 ? 1 : 0;
	}
	cout << score << " " << lstr << " " << answer.size() << '\n';
	
}
void input() {
	int w;
	for (int i = 0; i < 9; i++)
		root[i] = new Trie;
	int n;

	cin >> w;
	for (int i = 0; i < w; i++) {
		string str;
		cin >> str;
		const char* word = str.c_str();
		root[str.length()]->insert(word); //길이에 맞추어 넣는다.
	}
	cin >> n;
	while (n--) {
		answer.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> arr[i][j];
			}
		}
		solve();
	}
}
int main() {
	PREPROCESS;
	input();
	return 0;
}