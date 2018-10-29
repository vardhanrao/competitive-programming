#include<bits/stdc++.h>
using namespace std;

typedef struct trieNode{
    int val;
    trieNode* children[2];
};

trieNode* createTrieNode(){
    trieNode* newNode = new trieNode;
    newNode->val = -1;
    newNode->children[0] = NULL;
    newNode->children[1] = NULL;
    return newNode;
}

void insert(trieNode* root,int x){
    trieNode* p = root;
    for(int i = 31;i>=0;i--){
        bool cur_bit = x & (1 << i);
        if(!p->children[cur_bit])
            p->children[cur_bit] = createTrieNode();
        p = p->children[cur_bit];
    }
    p->val = x;
}

int helper(trieNode* root,int x){
    trieNode* p = root;
    for(int i = 31;i>=0;--i){
        bool cur_bit = x & (1 << i);
        if(p->children[1 - cur_bit])
            p = p->children[1 - cur_bit];
        else if(p->children[cur_bit])
            p = p->children[cur_bit];
    }
    return x ^ p->val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> vec(n);
        for(int i = 0;i<n;i++)
            cin>>vec[i];
        
        trieNode* root = createTrieNode();
        insert(root,vec[0]);
        int max_xor = INT_MIN, i = 1;
        for(;i < n;++i){
            max_xor = max(max_xor,helper(root,vec[i]));
            insert(root,vec[i]);
        }
        cout<<max_xor<<endl;
    }
}