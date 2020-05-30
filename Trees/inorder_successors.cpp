#include<iostream>

using namespace std;

/*

Given a Binary Tree where each node has following structure, write a function to populate next pointer for all nodes. 
The next pointer for every node should be set to point to inorder successor.

*/

struct node{

    int data;
    node *lchild, *rchild, *next;

};

node* newNode(int data){

    node *newnode = new node();
    newnode->lchild = NULL ;
    newnode->rchild = NULL ;
    newnode->next = NULL ;
    newnode->data = data;
    
    return newnode;

}

void InorderSuccessor(node *root, node *&prevNode){

    // return if root is null
    if (!root){
        return ;
    }

    InorderSuccessor(root->rchild, prevNode) ;
    root->next = prevNode ;
    if (prevNode){
        cout << "Next for current node " << root->data << " is: "  << prevNode->data << endl ;
    }
    prevNode = root ;
    InorderSuccessor(root->lchild, prevNode) ;

}

int main(){

    // Building up a test tree
    node *root;

    root = new node();

    root->data = 10;
    root->lchild = newNode(20);
    root->rchild = newNode(30);
    root->lchild->lchild = newNode(40);
    root->lchild->rchild = newNode(50);
    root->rchild->lchild = newNode(66);
    root->rchild->rchild = newNode(70);
    root->lchild->lchild->lchild = newNode(80);
    root->lchild->lchild->lchild->rchild = newNode(90);
    root->lchild->lchild->lchild->rchild->rchild = newNode(100);
    root->lchild->lchild->lchild->rchild->rchild->rchild = newNode(110);

    node *prevNode = NULL;
    
    InorderSuccessor(root, prevNode) ;




}