#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> arr;
    for(int i=0;i<arr1.size();i++){
        int x = arr1[i]|arr2[i];
        arr.push_back(x);
    }
    for(int i=0;i<n;i++){
        string str="";
        int j=0;
        while(j<n){
            if(1<<(n-1-j) & arr[i])
                str+="#";
            else str+=" ";
            j++;
        }
        answer.push_back(str);
    }
    return answer;
}