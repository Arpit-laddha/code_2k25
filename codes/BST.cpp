#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        left=right=NULL;
        val=data;
    }
};
class BST{
public:
    Node* root;
    BST(){
        root=NULL;
    }
   
    Node* insert(Node* root,int key){
        Node* new_node = new Node(key);
        if(root==NULL) return new_node;
        if(key<root->val){
            root->left=insert(root->left,key);
        }else{
            root->right=insert(root->right,key);
        }
        return root;
    }
    
    Node* getSuccessor(Node* temp){
        temp=temp->right;
        while(temp!=NULL && temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }

    Node* preDecessor(Node* temp){
        temp=temp->left;
        while(temp && temp->right) temp=temp->right;
        return temp;
    }

    Node* del(Node* root,int key){
        if(!root) return root;
        if(root->val<key){
            root->right=del(root->right,key);
        }
        else if(root->val>key){
            root->left=del(root->left,key);
        }else{
            Node* temp=root;
            if(!root->left && !root->right) return NULL; //Leaf node case
            if(root->right) return root->right; //Right child presesnt but no Left Child
            if(root->left) return root->left; //Left Child Present but no right child
            Node* succ=getSuccessor(root); //Successor and Predeccessor are always leaf nodes;
            swap(root->val,succ->val);
            root->right=del(root->right,succ->val);
            free(temp);
        }
        return root;
    }

    bool search(Node* temp,int key){
        if(!temp) return false;
        if(temp->val==key) return true;
        else if(temp->val<key) return search(temp->right,key);
        else return search(temp->left,key);
    }

    void inorder(Node* temp){
        if(temp==NULL) return;
        if(temp->left) inorder(temp->left);
        cout<<temp->val<<" ";
        if(temp->right) inorder(temp->right);
    }
};
int main(){
    BST tree1;
    tree1.root=tree1.insert(tree1.root,2);
    tree1.root=tree1.insert(tree1.root,1);
    tree1.root=tree1.insert(tree1.root,5);
    tree1.root=tree1.insert(tree1.root,3);
    tree1.root=tree1.del(tree1.root,5);
    tree1.root=tree1.insert(tree1.root,4);
    tree1.root=tree1.del(tree1.root,3);
    tree1.inorder(tree1.root);
    cout<<tree1.search(tree1.root,4)<<" "<<tree1.search(tree1.root,3);
    return 0;
}