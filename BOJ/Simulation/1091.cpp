#include <iostream>
#include <algorithm>


using namespace std;

int N;
int P[50];
int S[50];
int card[50];
int answer=0;
bool check(){
    for(int i=0;i<N;i++){
        if(card[i]%3!=P[i]) return false;
    }
    return true;
}
bool shuffle(){
    int tmp[50];
    for(int i=0;i<N;i++){
        //S의 순서로 바뀐다
        tmp[i]=card[S[i]];
    }
    for(int i=0;i<N;i++){
        card[i]=tmp[i];
    }
    bool first = true;
    for(int i=0;i<N;i++){
        if(card[i]!=i){
            first=  false;
            break;
        }
    }
    if(first && answer>0) return false; //처음이 아닌데 원래대로 돌아온 경우
    return true;
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>P[i];
        card[i]=i;
    }
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    bool possible = false;
    while(true){
        if(check()) break;
        if(!shuffle()){
            possible= true;
            break;
        }
        answer++;
    }
    
    cout<< (possible ? -1 : answer) <<'\n';
    return 0;
}