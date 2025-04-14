#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data=value;
        left=right=nullptr;
    }

};

void preorder(Node* root){
    if(root==nullptr)return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==nullptr)return;
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==nullptr)return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root){
    vector<vector<int>>ans;

    if(root==nullptr)return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(temp->left!=nullptr)q.push(temp->left);
            if(temp->right!=nullptr)q.push(temp->right);
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }

    for(int i=0; i<ans.size();i++){
        cout<<"[";
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
}


int main(){

    Node* root= new Node(1);

    root->left= new Node(2);
    root->right= new Node(3);
    root->left->left= new Node(4);
    root->left->right= new Node(5);
    root->right->left= new Node(6);
    root->right->right= new Node(7);

    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelOrder(root);
    

    return 0;
}
