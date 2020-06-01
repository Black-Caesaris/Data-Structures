#include<iostream>

/*

Check if removing an edge can divide a Binary Tree in two halves

*/

using namespace std;

bool flag;
int lcount, rcount;
struct node{
    int data;
    node *lchild, *rchild;
};


node* newNode(int data){

    node *newnode = new node();
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->data = data;
    return newnode;

}

int countNodes(node *root, int *nodeCount){

    if(!root){
        return 0;
    }

    *nodeCount += 1;
    countNodes(root->lchild, nodeCount);
    countNodes(root->rchild, nodeCount);

    return *nodeCount;

}

void checkEqualTrees(node *root, int totalNodes){

    if(!root){
        return;
    }

    if(root->lchild != NULL){
        countNodes(root->lchild, &lcount);
        if (lcount == (totalNodes / 2)){
            flag  =  true;
        }
        lcount = 0;
    }

    if(root->rchild != NULL){
        countNodes(root->rchild, &rcount);
        if (rcount == (totalNodes / 2)){
            flag  =  true;
        }
        rcount = 0;
    }

    checkEqualTrees(root->lchild, totalNodes);
    checkEqualTrees(root->rchild, totalNodes);

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

    static int *nodeCount;
    int x = 0;
    nodeCount = &x;

    flag = false;

    // calculate total number of elements
    int totalNodes = countNodes(root, nodeCount);
    cout << endl;
    checkEqualTrees(root, totalNodes);
    if(flag){
        cout << "Yes";
    }else{
        cout << "No";
    }

}