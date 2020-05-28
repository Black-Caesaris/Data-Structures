#include<iostream>


using namespace std;

struct node{

    int data;
    node *lchild, *rchild;

};

node* newNode(int data){
    node *newNode;
    newNode->data = data;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    return newNode;
}


int search(int array[], int root, int size){
    for (int i = 0 ; i < size ; i++){
        if(array[i] == root){
            return i;
        }
    }
    return -1;
}

void printPostOrder(int inorder[], int preorder[], int size){

    int root = search(inorder, preorder[0], size);

    if( root != 0)
        printPostOrder(inorder, preorder + 1, root);

    if( root != size - 1)
        printPostOrder(inorder + root + 1, preorder + root + 1, size - root - 1);

    cout << preorder[0]<< " ";

}

int main(){

    int inorder[] = {4, 2, 9, 5, 1, 8, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 9, 3, 6, 8, 7};
    printPostOrder(inorder, preorder, sizeof(inorder)/sizeof(inorder[0]));

    return 0;
    
}