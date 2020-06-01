#include<iostream>
 
 using namespace std;


float lsum = 0, rsum = 0;
struct node{
    int data;
    node *lchild, *rchild;   
};

node* newNode( int data ){
    node *newnode = new node();
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}


bool checkSumTree( node *root ){

    if( root == NULL || ( root->lchild == NULL && root->rchild == NULL )){
        return true;
    }


    checkSumTree( root->rchild );
    checkSumTree( root->lchild );

    if( root->lchild != NULL){
        lsum += root->lchild->data;
        cout << "lsum: " << lsum << endl;
    }    
    
    if( root->rchild != NULL){
        rsum += root->rchild->data;
        cout << "rsum: " << lsum << endl;
    }    

    if (root->data == ( lsum + rsum ) ){
        return true;
    }else{
        return false;
    }

    // if( ( checkSumTree( root->lchild ) && checkSumTree( root->rchild )) && ( root->data == lsum + rsum ) ){
    //     return true;
    // }else{
    //     return false;
    // }

}


int main(){

    // Building up a test tree
    node *root;

    root = new node();
    root->data = 40;
    root->lchild  = newNode(10); 
    root->rchild = newNode(10); 
    root->lchild->lchild = newNode(5); 
    root->lchild->rchild = newNode(5); 
    root->rchild->rchild = newNode(5); 
    root->rchild->lchild = newNode(5); 

    if(checkSumTree(root)) 
        cout << "The given tree satisfies "
            << "the children sum property "; 
    else
        cout << "The given tree does not satisfy "
            << "the children sum property "; 

}