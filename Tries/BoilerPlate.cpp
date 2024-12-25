#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node *newNode){
        links[ch-'a']=newNode;
    }   
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        this->flag=true;
    }
    bool isEnd(){
        return this->flag;
    }
};

class Trie {
private:
    Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    // TC=O(len(word))
    void insert(string word) {
        Node *temp = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(!temp->containsKey(word[i])){
                Node *newNode = new Node();
                temp->put(word[i], newNode);
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }

    /** Returns if the word is in the trie. */
    // TC=O(len(word))
    bool search(string word) {
        Node *temp = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            if(!temp->containsKey(word[i])){
                return false;
            }
            temp = temp->get(word[i]);
        }
        return temp->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    // TC=O(len(word))
    bool startsWith(string prefix) {
        Node *temp = root;
        int n = prefix.size();
        for(int i=0;i<n;i++){
            if(!temp->containsKey(prefix[i])){
                return false;
            }
            temp = temp->get(prefix[i]);
        }
        return true;
    }
};