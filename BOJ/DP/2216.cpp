#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

long long sum[3001][3001]; 
int main(){
	int a, b, c;
	string str1, str2;
	char s1[3001], s2[3001];
	cin >> a >> b >> c >> str1 >> str2;
	for (int i = 1; i <= str1.length(); i++) {
		s1[i] = str1.at(i - 1);
		sum[i][0] = i * b;
	}
	for (int i = 1; i <= str2.length(); i++) {
		s2[i] = str2.at(i - 1);
		sum[0][i] = i * b;
	}

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {
			if (s1[i] == s2[j])
				sum[i][j] = sum[i - 1][j - 1] + a;
			else {
				sum[i][j] = max(sum[i - 1][j] + b, sum[i][j - 1] + b);
				sum[i][j] = max(sum[i][j], sum[i - 1][j - 1] + c);
			}
		}
	}
	cout << sum[str1.length()][str2.length()] << endl;
}