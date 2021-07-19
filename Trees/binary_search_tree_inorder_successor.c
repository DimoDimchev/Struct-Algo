#include<stdlib.h>
#include<stdio.h>

struct TreeNode{ // node for the binary tree
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* GenerateNode(int data){ // generate new node
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* Insert(struct TreeNode* root,int data){ // insert new node using recursion
    if(root == NULL){
        root = GenerateNode(data);
        return root;
    }
    if(data <= root->data){
        root->left = Insert(root->left, data); // recursion call
    } else {
        root->right = Insert(root->right, data); // recursion call
    }
    return root;
}

struct TreeNode* Search(struct TreeNode* root, int data){ // search for a specific element recursively
    if(root == NULL) return 0;
    else if(root->data == data) return root;
    else if(data <= root-> data) return Search(root->left, data);
    else return Search(root->right, data);
}

struct TreeNode* FindMin(struct TreeNode* root){
    if(root == NULL){
        printf("Error: tree is empty");
        return -1;
    }
    else if(root->left == NULL) return root;
    return FindMin(root->left);
}

struct TreeNode* GetSuccessor(struct TreeNode* root, int data){
    struct TreeNode* current = Find(root, data);
    if(current == NULL){
        return current;
    }
    // Case 1: Node has right subtree
    if(current->right != NULL){
        return FindMin(current->right);
    }
    // Case 2: Node doesn't have a right subtree
    else {
        struct TreeNode* successor = NULL;
        struct TreeNode* ancestor = root;
        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            } else{
                ancestor = ancestor->right;
            }
            return successor;
        }
    }
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    struct TreeNode* root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 15);
    root = Insert(root, 2);
    root = Insert(root, 5);
    root = Insert(root, 3);
}