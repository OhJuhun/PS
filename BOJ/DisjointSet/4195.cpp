#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAX 987654321
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)

map<string, string> parent; //부모관계 확인
map<string, int> friends;

int T, F;
string Find(string n) {
	if (parent[n] == "") {
		friends[n]++;
		return parent[n]=n;
	}
	return n == parent[n] ? n : parent[n] = Find(parent[n]);
}

void Union(string a, string b) {
	a = Find(a);
	b = Find(b);
	
	if (a != b) {
		parent[b] = a;
		friends[a] += friends[b];
	}
}
int main(){
	PREPROCESS;
	cin >> T;
	while (T--) {
		cin >> F;
		parent.clear();
		friends.clear();
		while (F--) {
			string a, b;
			cin >> a >> b;
			Union(a, b);
			a = Find(a);
			cout << friends[a] << '\n';
		}
	}
	return 0;
}