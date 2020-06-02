#include<iostream>

/*

   Given a binary tree containing n nodes. The problem is to find the sum of all the parent node’s which have a child node with value x. 

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

int sumParents(node *root, int nodeData){

    if(!root){
        return 0;
    }

    int sumLeft = sumParents(root->lchild, nodeData);
    int sumRight = sumParents(root->rchild, nodeData);  

    int sum = 0;

    if (root->lchild != NULL ){
        if(root->lchild->data == nodeData){
            sum += root->data;
        }
    }     

    if (root->rchild != NULL ){
        if(root->rchild->data == nodeData){
            sum += root->data;
        }
    }   

    return sum + sumLeft + sumRight;

}

int main(){

    // Building up a test tree
    node *root;

    root = new node();

    root->data = 4;
    root->lchild  = newNode(2); 
    root->rchild = newNode(5); 
    root->rchild->lchild = newNode(2); 
    root->rchild->rchild = newNode(3); 
    root->lchild->lchild = newNode(7);  
    root->lchild->rchild = newNode(2);

    int sum = sumParents(root, 2);
    cout << sum;

}
