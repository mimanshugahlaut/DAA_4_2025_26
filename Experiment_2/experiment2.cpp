#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
using namespace std;
struct Node{
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c,int f) {
        ch=c;
        freq=f;
        left=right=NULL;
    }
};
struct compare{
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};
void generateCodes(Node* root,string code,unordered_map<char,string>& huffmanCode) {
        if(!root) return;
        if (!root->left && !root->right)
        huffmanCode[root->ch]=code;
    
        generateCodes(root->left, code + "0", huffmanCode);
        generateCodes(root->right, code + "1", huffmanCode);
} 
string decode(Node* root, string encoded) {
    string decoded = "";
    Node* curr = root;
    for (char bit : encoded) {
        if (bit == '0')
            curr=curr->left;
        else
            curr=curr->right;
        
        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}
int main(){
    string s;
    cout<<"Enter input string: ";
    getline(cin,s);
    
    unordered_map<char,int> freq;
    for(char c:s)
    freq[c]++;
    
    priority_queue<Node*,vector<Node*>,compare>pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));
        
    while(pq.size()>1){
        Node* left=pq.top(); pq.pop();
        Node* right=pq.top(); pq.pop();
        
        Node* newNode=new Node('$',left->freq+right->freq);
        newNode->left=left;
        newNode->right=right;
        
        pq.push(newNode);
    }
    Node* root=pq.top();
    
    unordered_map<char,string> huffmanCode;
    generateCodes(root,"",huffmanCode);
    
    string encoded="";
    for(char c:s)
    encoded+=huffmanCode[c];
    
    string decoded=decode(root,encoded);
    
    cout<<"Original String:"<<s<<endl;
    cout<<"Encoded String:"<<encoded<<endl;
    cout<<"Decoded String:"<<decoded<<endl;
    
    return 0;
}
