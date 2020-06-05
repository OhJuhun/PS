#include <string>
#include <vector>
#include <iostream>
using namespace std;
//n x m m x l = n x l
/*
[1,4] [3,3]
[3,2] [3,3]
[4,1]
0,0~ 0,m까지 0,0~m,0까지
1,0~ 1,m까지 0,1~m,1까지
n,0~ n,m까지 
*/
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int l = arr2[0].size();
    int n = arr1.size();
    int m = arr2.size();
    for(int i=0;i<n;i++){
        vector<int> tmp(l); answer.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            for(int k=0;k<m;k++){
                answer[i][j] += arr1[i][k]* arr2[k][j];
            }
        }
    }
    return answer;
}