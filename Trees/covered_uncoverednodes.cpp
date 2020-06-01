#include<iostream>


/*

Given a binary tree, you need to check whether sum of all covered elements is equal to sum of all uncovered elements or not.
In a binary tree, a node is called Uncovered if it appears either on left boundary or right boundary. Rest of the nodes are called covered.

*/

using namespace std;

struct node{

    int data;
    node *lchild, *rchild;

};

node* newNode(int data){
    node* newnode = new node();
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->data = data;
    return newnode;
}

float sumLeftBoundary(node *root){
    float sum = 0;
    while(true){
        if (root->lchild != NULL){
            sum += root->lchild->data;
            root = root->lchild;
        }else{
            break;
        }
    }
    return sum;
}
float sumRightBoundary(node *root){
    float sum = 0;
    while(true){
        if (root->rchild != NULL){
            sum += root->rchild->data;
            root = root->rchild;
        }else{
            break;
        }
    }
    return sum;
}

void sumTree(node *root, int *sum){

    if (!root ){
        return ;
    }

    sumTree(root->lchild, sum);
    sumTree(root->rchild, sum);
    *sum += root->data;
}


bool checkCovered(node *root){

    int lsum = 0, rsum = 0;
    if( !root ){
        return true;
    }

    lsum = sumLeftBoundary(root);
    rsum = sumRightBoundary(root);
    cout << lsum;
    cout<<  rsum;
    int sum = 0;
    static int *sumptr = &sum;

    sumTree(root, sumptr);
    cout << sum;
    if ((sum == 2*(lsum + rsum + root->data)) && checkCovered(root->lchild) && checkCovered(root->rchild)){
        return true;
    }else{
        return false;
    }


}

int main(){

    // Building up a test tree
    node *root;

    root = new node();
    root->data = 1;
    root->lchild  = newNode(2); 
    root->rchild = newNode(3); 
    root->lchild->lchild = newNode(4); 
    root->lchild->rchild = newNode(5); 
    root->lchild->rchild->rchild = newNode(5); 


    if(checkCovered(root)) 
        cout << "The given tree satisfies "
            << "the children sum property "; 
    else
        cout << "The given tree does not satisfy "
            << "the children sum property "; 

}