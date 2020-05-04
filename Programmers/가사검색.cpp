#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Trie{
    bool terminal;
    int cnt;
    Trie* next[26];
    Trie() : cnt(0),terminal(false){
        memset(next,0,sizeof(next));
    }
    ~Trie(){
        for (int i=0;i<26;i++)
            if(next[i]) delete next[i];
    }
    
    void insert(const char* key){
        if(*key == '\0') terminal = true;
        else{
            int cur = *key - 'a';
            if (next[cur] == NULL) next[cur] = new Trie();
            else next[cur]->cnt++;
            next[cur]->insert(key+1);
        }
    }
    
    int find(const char* key){
        int ret=0;
        if(*key == '?'){
            for(int i=0;i<26;i++){
                if(next[i]!=NULL) ret += next[i]->cnt+1;
            }
            return ret;
        }
        if(*key == '\0' && terminal) return 1;
        int cur = *key - 'a';
        if(next[cur] == NULL) return 0; 
        return next[cur]->find(key+1);
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie* root[10001];
    Trie* back[10001];
    for(int i=0;i<10001;i++)
        root[i]= new Trie, back[i] = new Trie;
    for(string word: words){
        const char* c = word.c_str();
        root[word.length()]->insert(c);
        string s = word;
        reverse(s.begin(),s.end());
        const char* cr = s.c_str();
        back[word.length()]->insert(cr);
    }
    
    for(string query : queries){
        string str = query;
        int ans=0;
        if(str[0]=='?'){
            if(back[query.length()]==NULL){
                answer.push_back(0); continue;
            }
            reverse(str.begin(),str.end());
            const char* c = str.c_str();
            ans=back[query.length()]->find(c);
        }
        else{
            if(root[query.length()]==NULL){
                answer.push_back(0); continue;
            }
            const char* c = str.c_str();
            ans=root[query.length()]->find(c);
        }
        answer.push_back(ans);
    }
    return answer;
}