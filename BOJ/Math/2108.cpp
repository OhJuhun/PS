#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned int uint;

int main() {
	uint n;
	vector <int> val;

	double s = 0; // double 형으로 새로운 변수 하나 추가
	int sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int temp; cin >> temp;
		sum += temp; 
        s += temp; // 입력된 모든 값 더한 결과 저장
		val.push_back(temp);

	}
	//입력
	printf("%.0f\n", (s / val.size()));  //산술평균 -> int 형 sum 변수 대신에 double 형 s 변수로 대체
            //-> %.0f 뿐만아닌 해당 형식문자에 맞는 변수의 자료형 또한 매칭시킴으로써 AC 나옴 
    
	sort(val.begin(), val.end());
	cout << val[(int)(val.size() / 2)] << endl;
	reverse(val.begin(), val.end());
	//최빈값
	vector <int>::iterator iter;
	int many = 0;  //최대 원소
	int manycount = 0;  //최대 원소의 갯수
	int postmany = 0;
	int i = 0;
	for (iter = val.begin(); iter != val.end();) {
		int temp = count(iter, val.end(), val[i]);
		if (manycount == temp) {
			postmany = many;
			many = val[i];
		}
		else if (manycount < temp) {
			postmany = 0;
			manycount = temp;
			many = val[i];
		}

		for (int j = 0; j < temp; j++) {
			iter++; i++;
		}
	}
	if (postmany == 0) {
		cout << many << endl;
	}
	else {
		cout << postmany << endl;
	}

	//범위
	cout << val[0] - val[val.size() - 1] << endl;
	return 0;
}