#include <iostream>
#include <string>
using namespace std;


void ironMan(){
    cout<<"I AM IRONMAN!!"<<endl;
}

void notIronMan(){
    cout<<"I AM NOT IRONMAN!!"<<endl;
}
string splitFirst(string str){
    return str.substr(0,str.length()-2);
}
char splitSecond(string str){
    return str.at(str.length()-1);
}
int main(){
    pair<string, char> player_info[1001];
    int N; // total games
    int P; // total players
    //under 1000 Natural Number
    
    int W; // if win get W
    int L; // if lose lost L 
    //0<=W,L<=100
    int G; // goal
    //1<=G<=100000
    cin>>N>>P;
    cin>>W>>L>>G;
    string info;
    char WL;
    for(int i=0;i<P;i++){
        cin>>info;
        cin>>WL;
        player_info[i].first=info;
        player_info[i].second=WL;
    }
    int score=0;
    bool success=false;
    for(int i=0;i<N;i++){
        cin>>info;
        bool isHacked=false;
        for(int j=0;j<P;j++){
            if(player_info[j].first==info){
                if(player_info[j].second=='W')
                    score+=W;
                else{
                    if(score-L<=0)
                        score=0;
                    else
                        score-=L;
                }
                isHacked=true;
                break;
            }
        }
        if(score>=G)
            success=true;
        if(!isHacked){
            if(score-L<=0)
                score=0;
            else
                score-=L;
        }
    }
    if(!success)
        ironMan();
    else
        notIronMan();
    return 0;
}
