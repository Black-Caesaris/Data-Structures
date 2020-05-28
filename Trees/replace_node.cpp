#include<iostream>
#include<iterator>
#include<vector>

using namespace std;

struct node {
    int data;
    node *lchild, *rchild;
};

node *newNode(int data){

    node *newnode =  new node();
    newnode->data = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;

    return newnode;

}



void Inorder(node *root, vector<int> *v){

    if ( root == NULL ){
        return;
    }

    Inorder(root->lchild, v);
    cout << root->data << "\t";
    v->push_back(root->data);
    Inorder(root->rchild, v);

}


void predSuccAddition(vector<int> *v){

    vector<int>::iterator vi;
    int prevElement = *(v->begin());
    int currElement;

    for( vi = v->begin() + 1; vi != v->end() - 1; vi++ ){

        currElement = *vi;
        *vi = prevElement + *(vi + 1);
        prevElement = currElement;

    }

    cout << endl;

    for( vi = v->begin() + 1 ; vi != v->end() -  1; vi++ ){
       cout << *vi << "\t";
    }



}


void Replace(node *root){

    vector<int> v;
    v.push_back(0);
    cout << " Original Inorder: " << endl;
    Inorder(root, &v);
    v.push_back(0);

    cout << "Result: ";
    predSuccAddition(&v);


}


int main(){

    // Building up a test tree
    node *root;

    root = newNode(10);
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


    Replace(root);

}