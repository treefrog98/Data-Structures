#include<iostream>
#include<vector>
#include <queue>
#include<algorithms>
using namespace std;


struct TreeNode{
  int data;
  TreeNode* left;
  TreeNode* right;
}

// count the number of nodes in a tree
int countNodes(TreeNode* root){
  if(root == NULL){
    return 0;
  }
  else{
    return countNodes(root->left)+countNodes(root->right)+1;
  }
}
// preorder traversal of tree
void preOrderTraversal(TreeNode* root){
  // traverse if root exists
  if(root != NULL){
    cout<<root->data<<endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}
// inorder traversal of tree
void inOrderTraversal(TreeNode* root){
  // traverse if root exists
  if(root != NULL){
    inOrderTraversal(root->left);
    cout<<root->data<<endl;
    inOrderTraversal(root->right);
  }
}
// postorder traversal of tree
void postOrderTraversal(TreeNode* root){
  // traverse if root exists
  if(root != NULL){
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<endl;
  }
}

// BFS (level order traversal for tree)
void BFS(TreeNode* root){
  if(root == null){
    return;
  }
  // create queue structure for BFS (empty)
  queue<TreeNode*>bfsqueue;
  // initialize first element (root)
  bfsqueue.push(root);
  while(bfsqueue.empty()== false){
    // deque the front element (print it too)
    TreeNode* front = bfsqueue.front();
    cout<<front->data<<endl;
    // remove
    bfsqueue.pop();

    // get the left and right child
    if(front->left != NULL){
      bfsqueue.push(front->left);
    }
    if(front->right != NULL){
      bfsqueue.push(front->right);
    }
  }
}
int maxDepth(TreeNode* root){
  if(root == NULL){
    return 0;
  }
  else{
    int rightDepth = maxDepth(root->right);
    int leftDepth = maxDepth(root->left);
    if(leftDepth > rightDepth){
      return leftDepth+1;
    }
    else{
      return rightDepth+1;
    }
  }
}





// BST Application

struct BSTNode{
  int data;
  BSTNode* left;
  BSTNode* right;

  // constructor
  BSTNode(int input){
    data = input;
    // set left and right pointers to NULL
    left = NULL;
    right = NULL;
  }
}
bool containsNode(int search){
  if(root == NULL){
    return false;
  }
  if(root->data == search){
    return true;
  }
  if(root->data < search){
    return containsNode(root->left, search);
  }
  else{
    return containsNode(root->right, search);
  }
}
void insertNode(TreeNode*& root, int data){
  if(root == NULL){
    // create root
    root = new BSTNode(data);
    return;
  }
  else if(root->data < data){
    insertNode(root->left,data);
  }
  else{
    insertNode(root->right,data);
  }
}
// find min value of tree
int minValue(BSTNode* root){
  struct BSTNode* current = root;
  // go as far left as you can
  while(current->left != NULL){
    current = current->left;
  }
  return current->data;

}
void mirror(BSTNode* root){
  if(root == NULL){
    return;
  }
  else{
    struct BSTNode* temp;
    // use pointers later
    mirror(root->left);
    mirror(root->right);

    // swap
    temp = root->left;
    // set to other side
    root->left = root->right;
    root->right = temp;
  }
}

// test if 2 trees are the same
int sameTree(BSTNode* tree1, BSTNode* tree2){
  if(tree1 == NULL && tree2 == NULL){
    return (true);
  }
  else if(tree1!= NULL && tree2 != NULL){
    return tree1->data == tree2->data && sameTree(tree1->left, tree2->left) && sameTree(tree1->right, tree2->right);
  }
  else{
    // all else fails
    return false;
  }
}
