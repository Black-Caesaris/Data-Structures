#include<iostream>

using namespace std;

int heightOfNode;
int parentNode;

struct node{
    int data;
    node *lchild, *rchild;
};

node *newNode(int data){
    node *newnode = new node();
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

int HeightOfNode(node *root, int nodeData, int height){

    if(!root){
        return height;
    }

    int level = HeightOfNode(root->lchild, nodeData, height + 1);

    if(root->data == nodeData)
        heightOfNode = level;

    level = HeightOfNode(root->rchild, nodeData, height + 1);

    if(root->data == nodeData)
        heightOfNode = level;

    return height;

}

void findParentNode(node *root, int nodeData){

    if(!root){
        return;
    }

    findParentNode(root->lchild, nodeData);
    if (root->lchild != NULL){
        if(root->lchild->data == nodeData)
            parentNode = root->data;
    }


    findParentNode(root->rchild, nodeData);
    if (root->rchild != NULL){
        if(root->rchild->data == nodeData)
            parentNode = root->data;
    }
}

bool checkCousin(node *root, int nodeData1,int nodeData2){

    if (!root){
        return false;
    }

    int height = -1;
    int heightNode1 = HeightOfNode(root, nodeData1, height);
    int heightNode2 = HeightOfNode(root, nodeData2, height);

    parentNode = -1;
    findParentNode(root, nodeData1);
    int parentNode1 = parentNode;
    findParentNode(root, nodeData2);
    int parentNode2 = parentNode;

    if (heightNode1 == heightNode2 && parentNode1 == parentNode2){
        return true;
    }

    return false;

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

    bool result = checkCousin(root, 66, 70);
    cout << result;


}