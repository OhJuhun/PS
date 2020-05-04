#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

bool check(string str){
    stack<char> s;
    for(char c:str)
        if(c=='(') s.push(c);
        else{
            if(s.empty()) return false;
            else s.pop();
        }
    return true;
}
string divide(string w){
    if(w=="") return w;
    string u="",v="";
    int open = 0,close = 0;
    int idx=0;
    for(int i=0;i<w.length();i++){
        if(w[i]=='(') open++;
        else close++;
        if(open==close){
            u=w.substr(0,i+1);
            if(idx<w.length()-1)
                v=w.substr(i+1,w.length()-(i+1));
            break;
        }
    }
    cout<<u<<" "<<v<<endl;
    if(!check(u)){
        string str="("+divide(v)+")";
        string _u="";
        for(int i=1;i<u.length()-1;i++){
            if(u[i]=='(') _u+=')';
            else _u+='(';
        }
        u=_u;
        str+=u;
        return str;
    }
    return u+divide(v);
}
string solution(string p) {
    string answer = "";
    answer = divide(p);
    return answer;
}