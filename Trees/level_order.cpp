#include<iostream>
#include<queue>

using namespace std;

class TreeNode {

    public:

    int data;
    TreeNode *lchild, *rchild;

    // default constructor
    TreeNode();

    // paramterised constructor
    TreeNode(int);

    // New node function
    TreeNode* NewNode(int);

    // In order traversal
    void Inorder(TreeNode *);

    // level order function
    void LevelOrder(TreeNode *, queue <TreeNode *> *);

    // Height of tree
    int Height(TreeNode *, int *);


};

TreeNode :: TreeNode() : data(0), lchild(NULL), rchild(NULL){}

TreeNode :: TreeNode(int value){

    data = value;
    lchild = rchild = NULL;

}

TreeNode * TreeNode :: NewNode(int value){

    return new TreeNode(value);

}

void TreeNode :: Inorder (TreeNode *root){

    if (!root){
        return;
    }

    Inorder(root->lchild);
    cout << root->data << "\t";
    Inorder(root->rchild);

}

void TreeNode :: LevelOrder(TreeNode *root, queue <TreeNode *> *q){


// Loop till the queue is not empty 
 while (!q->empty()){
    
    // initialise a treeNode object to store a treeNode queue object
    TreeNode *treeNode;

    // get the front value of the queue
    // this value has to be printed
    treeNode = q->front();
    cout << treeNode->data << "\t";

    /* push the left and right childs of the current queue 
    treeNode object onto the queue if they are not NULL */
    if (root->lchild != NULL){
        q->push(root->lchild); 
    }
    if (root->rchild != NULL)
    {
        q->push(root->rchild);
    }

    // pop the top of the queue, it's already printed
    q->pop();

    // change the root node to current top of queue
    root = q->front();
 }
 

}

int TreeNode :: Height(TreeNode *root, int *height){

    // return if child is NULL
    if(!root){
        // return the current height
        return *height;
    }

    // initialise the starting heights if left tree and right trees as zero
    int leftSubtreeHeight = 0, rightSubtreeHeight = 0;

    // increment height by 1 as you traverse a new level
    *height = *height + 1;

    // find the height of the left subtree
    leftSubtreeHeight = Height(root->lchild, &leftSubtreeHeight);

    // find height of the right subtree
    rightSubtreeHeight = Height(root->rchild, &rightSubtreeHeight);

    // find the height of the larger subtree
    if (leftSubtreeHeight >= rightSubtreeHeight){
        // add +1 for the root node
        return leftSubtreeHeight + 1;
    }else{
        // add +1 for the root node
        return rightSubtreeHeight + 1;
    }

}

int main(){

    // Building up a test tree
    TreeNode treeNode;

    TreeNode *root = treeNode.NewNode(10);
    root->lchild = treeNode.NewNode(20);
    root->rchild = treeNode.NewNode(30);
    root->lchild->lchild = treeNode.NewNode(40);
    root->lchild->rchild = treeNode.NewNode(50);
    root->rchild->lchild = treeNode.NewNode(66);
    root->rchild->rchild = treeNode.NewNode(70);
    root->lchild->lchild->lchild = treeNode.NewNode(80);
    root->lchild->lchild->lchild->rchild = treeNode.NewNode(90);
    root->lchild->lchild->lchild->rchild->rchild = treeNode.NewNode(100);
    root->lchild->lchild->lchild->rchild->rchild->rchild = treeNode.NewNode(110);


    //treeNode.Inorder(root);
    cout << endl;

    int height = 0;
    int x = treeNode.Height(root, &height) ;
    cout << endl;
   // cout<<x;

    queue<TreeNode *> q;
    q.push(root);
    treeNode.LevelOrder(root, &q);








}