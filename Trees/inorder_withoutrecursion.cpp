#include<iostream>
#include<stack>

using namespace std;

struct node {
    int data;
    node *lchild, *rchild;
};

void InorderWithoutRecursion(node *root){

     if ( root == NULL){
        return;
    }

    stack<node *> s;
    node *tempNode = root;
    node *ephemeralNode;
      
    while (tempNode != NULL){
        s.push(tempNode);
        tempNode = tempNode->lchild;
    }

    while(!s.empty()){
        if (s.top()->rchild != NULL){
            cout << s.top()->data << endl;
            ephemeralNode = s.top();
            s.pop();
            s.push(ephemeralNode->rchild);
            ephemeralNode = ephemeralNode->rchild;
            while (ephemeralNode != NULL ){
                if (ephemeralNode->lchild != NULL){
                    s.push(ephemeralNode->lchild);
                    ephemeralNode = ephemeralNode->lchild;
                }else{
                    break;
                }
            }
        }else{
            cout << s.top()->data << "\t" << endl;
            s.pop();
        }
    }
}

node* newNode(int data){

    node *root = new node();
    root->data = data;
    root->lchild = NULL;
    root->rchild = NULL;

    return root;

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

    InorderWithoutRecursion(root);

}
