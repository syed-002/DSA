#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

Node* build_inorder_binary_tree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node*root = new Node(d);
    root->left = build_inorder_binary_tree();
    root->right = build_inorder_binary_tree();
    return root;
}

int minn;
int maxx;

bool isBST(Node * root){
    //complete this method

    if(root==NULL){
        return true;
    }
    if(root->key<=minn || root->key> maxx){
        return false;
    }
    
    return isBST(root->left) and isBST(root->right);
}


int main(){
   
    Node*root = build_inorder_binary_tree();
    minn= INT_MIN, maxx = INT_MAX;
    cout << isBST(root)<< endl;

}