#include<bits/stdc++.h>
using namespace std;

class node
{
  public:
   int key;
   node *left;
   node *right;

   node(int key){
       this->key = key;
       left = right  = NULL;
   }
};


node* insert(node*root, int x){

    if(root==NULL){
        return new node(x);
    }
    if(root->key < x){
        root->right= insert(root->right, x);
    }
    else root->left = insert(root->left, x);
    return root;
}


void inorder(node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<< root->key<< " ";
    inorder(root->right);
    return;
}

//here nodes a and b are the inputs
int shortestDist(node * root,int a,int b){
    //Complete this method

    while(root!=NULL){
        if(root->key > a and root->key >b){
            root = root->left;
            
        }
        else if(root->key < a and root->key <b){
            root = root->right;
        }
        else break;
    }
    //root is the lca
    //from the lca node to distance between the 2 nodes

    if(a>b) swap(a, b);
    //cout<< a<< " " <<b<<endl;
    int l=0, r=0;
    node*temp = root;
    while(temp){
        if(temp->key > a){
            temp = temp->left;
            l++;
        }
        else if(temp->key < a){
            temp = temp->right;
            l++;
        }
        else{
            break;
        }
        cout<< "l: " << l << endl;
    }
    temp = root;
    while(temp){
       
       if(temp->key < b){
        temp = temp->right;
        r++;
       }
       else if(temp->key>b){
        temp = temp->left;
        r++;
       }
       else break;
        //cout<< "r: " << r << endl;
    }
    
    return l+r;
    
}

int main(){
    node*root = NULL;
    //int arr[]= {3,6,2,8,11,9,5,7,13};
    int arr[]= {10, 4, 15, 2, 5, 13, 22, 1, 14};
    for(int x:arr){
        root=insert(root,x);
    }

    inorder(root);
    cout<<endl;
    cout<< shortestDist(root, 2, 13)<< endl;

}