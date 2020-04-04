#include <iostream>
using namespace std;

#define MAX 987654321
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define SUCCESS cout<<"LADICA\n"
#define FAILURE cout<<"SMECE\n"

int N, L;

int parent[300001];
bool visit[300001];
int Find(int x) {
	return parent[x] == x ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	parent[a] = b;
	SUCCESS;
}
int main(){
	PREPROCESS;
	cin >> N >> L;
	for (int i = 1; i <= L; i++)
		parent[i] = i;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (!visit[a]) {
			visit[a] = true;
			Union(a, b);
		}
		else if (!visit[b]) {
			visit[b] = true;
			Union(b, a);
		}
		else if (!visit[Find(a)]) {
			visit[Find(a)] = true;
			Union(a, b);
		}
		else if (!visit[Find(b)]) {
			visit[Find(b)] = true;
			Union(b, a);
		}
		else {
			FAILURE;
		}

	}
	
	return 0;
}