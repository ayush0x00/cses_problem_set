#include <bits/stdc++.h>
using namespace std;
#define maxN 1e9+7

struct Node{
    char val;
    vector<Node*> child{26};
    bool isLast;

    bool containsKey(char ch){
        return child[ch-'a']==nullptr ? false : true;
    }

    void put(char ch, Node* node){
        child[ch-'a'] = node;
    }
    Node* get(char ch){
        return child[ch-'a'];
    }
};

class Trie{
    private: Node* root;
    public:
    Trie(){
        root =  new Node();
    }

    void insert(string word){
        Node* temp = root;
        for(auto ch:word){
            if (!temp->containsKey(ch)) temp->put(ch, new Node());
            temp = temp->get(ch);
        }
        temp->isLast = true;
    }

    bool search(string word){
        Node* temp = root;
        for(auto ch: word){
            if(!temp->containsKey(ch)) return false;
            temp = temp->get(ch);
        }
        return temp->isLast;
    }
};

Trie* root;

void solve(const string& word){
    vector<long long> dp_word(word.length()+1);
    dp_word[0]=1;

    for(int i=0;i<=word.length();i++){
        for(int j=0;j<i;j++){
            string temp = word.substr(j,i-j);
            bool present = root->search(temp);
            if(present){
                dp_word[i]+= dp_word[i-temp.length()]% 1000000007 ;
            }
        }
    }
    cout<<dp_word[word.length()] % 1000000007;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    root = new Trie();
    freopen("test_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    string word;
    cin>>word;
    int n;
    cin>>n;
    while (n--){
        string val;
        cin>>val;
        root->insert(val);
    }
    solve(word);
    return 0;
}