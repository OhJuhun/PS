#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

long long sum[101][21]; 
long long arr[101];
int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < 21; i++)
		sum[0][i] = 0;
	sum[0][arr[0]] = 1;

	for (int i = 1; i < N - 1; i++) {
		for (int j = 0; j < 21; j++) {
			if (sum[i - 1][j] == 0) continue; //
			if (j - arr[i] >= 0)
				sum[i][j - arr[i]] += sum[i - 1][j];
			//i-1번째까지 j가되는 경우의수 + j-arr[i-1]
			if (j + arr[i] <= 20)
				sum[i][j + arr[i]] += sum[i - 1][j];
		}
	}
	cout << sum[N-2][arr[N-1]]<<endl;
	//N-1까지 더해서 arr[N-1]이 되는 수
	return 0;
}