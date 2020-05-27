#include<iostream>

using namespace std;

class TreeNode{

    public:

    int data;
    TreeNode  *lchild, *rchild;

    // default constructor
    TreeNode();

    // Paraneterise function, assigns the data value
    TreeNode(int);


    // Insert function
    TreeNode* NewNode(int);

    // Remove function
    TreeNode* Remove(TreeNode *, int);

    // Replace data value
    TreeNode* Replace(TreeNode *, int);



    // Inorder Traversal
    void Inorder(TreeNode *);

    // Preorder Traversal
    void Preorder(TreeNode *);

    // Postorder Traversal
    void Postorder(TreeNode *);

};


TreeNode :: TreeNode() : data(0), lchild(NULL), rchild(NULL){}

TreeNode :: TreeNode(int value){

    data = value;
    lchild =  rchild = NULL;

}

TreeNode* TreeNode :: NewNode(int value){

  return new TreeNode(value);

}

void TreeNode :: Inorder(TreeNode *root){

        if(!root){

            return;

        }

        Inorder(root->lchild);
        cout << root->data << "\t";
        Inorder(root->rchild);

}

void TreeNode :: Preorder(TreeNode *root){

        if(!root){

            return;

        }

        cout << root->data << "\t";
        Preorder(root->lchild);
        Preorder(root->rchild);

}

void TreeNode :: Postorder(TreeNode *root){

        if(!root){

            return;

        }

        cout << root->data << "\t";
        Postorder(root->lchild);
        Postorder(root->rchild);


}



int main(){

TreeNode treenode;  

TreeNode *root = treenode.NewNode(1);
root->lchild = treenode.NewNode(2);
root->rchild = treenode.NewNode(3);

treenode.Inorder(root);

}