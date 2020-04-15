#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
 
using namespace std;
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int arr[10];
        for (int i = 0; i < 10; i++) {
            cin >> arr[i];
            int sum = 0;
            int r = 1;
            while (arr[i] > 0) {
                int tmp = arr[i] % 10;
                sum += tmp;
                arr[i] = arr[i] / 10;
            }
            arr[i] = sum;
        }
        sort(arr, arr + 10);
        cout <<"#"<<t<<" "<< arr[9] << " " << arr[0] << endl;
    }
    return 0;
}