#include<iostream>

using namespace std;

// Given a Binary Tree, check if all leaves are at same level or not.

int level;
bool flag;

struct node{
    int data;
    node *lchild, *rchild;
};

node* newNode(int data){
    node* newnode = new node();
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

int checkLeavesLevel(node *root, int height){

    if(!root){
        return height;
    }

    int levelLeftChild = checkLeavesLevel(root->lchild, height + 1);
    if (root->lchild == NULL && root->rchild  == NULL){
        if (level == -1)
            level = levelLeftChild;
        if (levelLeftChild != level)
            flag = false;
    }
    int levelRightChild = checkLeavesLevel(root->rchild, height + 1);
    if (root->lchild == NULL && root->rchild  == NULL){
        if (level == -1)
            level = levelLeftChild;
        if (levelRightChild != level)
            flag = false;
    }

    return height;

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
    // root->rchild->rchild->rchild = newNode(8); 
    flag = true;
    int height  = -1;
    level = -1;
    checkLeavesLevel(root, height);
    if (flag)
        cout  << "All the leaf nodes are on the same level!" << endl;
    else
        cout << "All the leaf nodes are not on the same level!" << endl;
    
}