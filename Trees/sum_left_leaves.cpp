#include<iostream>

/*
    Find sum of all left leaves in a given Binary Tree
*/
using namespace std;

struct node{
    int data;
    node *lchild, *rchild;
};

node* newNode(int data){
    node *newnode = new node();
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

int sumLeftLeaves(node *root){

    if(!root){
        return 0;
    }

    int sumLeft = sumLeftLeaves(root->lchild);
    int sumRight = sumLeftLeaves(root->rchild);
    int sum = 0;
    if(root->lchild != NULL && root->lchild->lchild == NULL && root->lchild->rchild == NULL){
        sum = root->lchild->data;
    }

    return sum + sumLeft + sumRight;

}

int main(){
    // Building up a test tree
    node *root;

    root = new node();

    root->data = 9;
    root->lchild  = newNode(8); 
    root->rchild = newNode(6); 
    root->rchild->lchild = newNode(1); 
    root->lchild->lchild = newNode(5);  
    root->lchild->rchild = newNode(2);

    root->rchild->rchild = newNode(6);
    root->rchild->rchild->lchild = newNode(6);
    int sum = sumLeftLeaves(root);
    cout << sum;
}   



