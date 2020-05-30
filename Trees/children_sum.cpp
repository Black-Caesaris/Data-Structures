#include<iostream>

using namespace std;

struct node{

    int data;
    node *lchild, *rchild;

};

float SumChildren(node *root){
    
    int leftChildValue = 0;
    int rightChildValue = 0;

    if ( root == NULL || (root->lchild == NULL && root->rchild == NULL )){
        return 1;
    }

    if ( root->lchild != NULL ){
        leftChildValue = root->lchild->data ;
    }

    if ( root->rchild != NULL ){
        rightChildValue = root->rchild->data ;
    }

    if ( ( root->data == leftChildValue + rightChildValue ) && SumChildren( root->lchild ) && SumChildren( root->rchild ) ){
        return 1;
    }else{
        return 0;
    }

}

node *newNode(int data){
    node *newnode = new node() ;
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

int main(){

    // Building up a test tree
    node *root;

    root = new node();
    root->data = 10;
    root->lchild  = newNode(8); 
    root->rchild = newNode(2); 
    root->lchild->lchild = newNode(3); 
    root->lchild->rchild = newNode(5); 
    root->rchild->rchild = newNode(2); 
    if(SumChildren(root)) 
        cout << "The given tree satisfies "
            << "the children sum property "; 
    else
        cout << "The given tree does not satisfy "
            << "the children sum property "; 


}