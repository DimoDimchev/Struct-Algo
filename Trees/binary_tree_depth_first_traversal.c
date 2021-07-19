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

void PreOrder(struct TreeNode* root){
    if(root == NULL) return;

    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct TreeNode* root){
    if(root == NULL) return;
    
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void PostOrder(struct TreeNode* root){
    if(root == NULL) return;
    
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    struct TreeNode* root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 15);
    root = Insert(root, 2);
    root = Insert(root, 5);
    root = Insert(root, 3);

    PreOrder(root);
    InOrder(root);
    PostOrder(root);
}