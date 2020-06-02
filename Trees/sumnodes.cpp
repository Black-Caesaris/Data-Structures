#include<iostream>

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

int sum(node *root){


    if(!root){
        return 0;
    }

    int sumLeft = sum(root->lchild);
    int sumRight = sum(root->rchild);

    int sum = sumLeft + sumRight + root->data;

    return sum;



}
int main(){

    // Building up a test tree
    node *root;

    root = new node();

    root->data = 5;
    root->lchild  = newNode(1); 
    root->rchild = newNode(6); 
    root->rchild->lchild = newNode(7); 
    root->rchild->rchild = newNode(4); 
    root->rchild->lchild->rchild = newNode(2);  
    root->rchild->lchild->lchild = newNode(3);  
    root->rchild->rchild->rchild = newNode(8); 
    root->rchild->rchild->rchild->rchild = newNode(1); 
    root->rchild->rchild->rchild->rchild->rchild = newNode(1); 
    root->rchild->rchild->rchild->rchild->lchild = newNode(1); 

    int sums = sum(root);
    cout << sums;

}