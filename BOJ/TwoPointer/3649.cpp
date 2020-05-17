#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int x;
    while(cin>>x){
        x*=10000000;
        int n;
        cin>>n;
        int blocks[1000000];
        for(int i=0;i<n;i++) cin>>blocks[i];
        int l  = 0;
        int r = n-1;
        int abvs = 0 ;
        int ansl=-1;
        int ansr=-1;
        sort(blocks,blocks+n);
        while(l<r){
            if(blocks[l]+blocks[r] == x){
                ansl = l; ansr = r; break;
            }
            else if(blocks[l]+blocks[r]>x) r--;
            else l++;
        }
        if(ansl==-1) cout<<"danger\n";
        else{
            cout<<"yes "<<blocks[ansl]<<" "<<blocks[ansr]<<'\n';
        }
    }
    return 0;
}