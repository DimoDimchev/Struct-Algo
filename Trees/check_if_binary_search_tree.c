#include<stdlib.h>
#include<stdio.h>
#include<limits.h>

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

int IsBstUtil(struct TreeNode* root, int minValue, int maxValue){
    if(root == NULL){
        return 1;
    }
    if(root->data > minValue && root->data < maxValue && IsBstUtil(root->left, minValue, root->data) == 1 && IsBstUtil(root->right, root->data, maxValue) == 1){
        return 1;
    } else{
        return 0;
    }
}

int IsBinarySearchTree(struct TreeNode* root){
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    struct TreeNode* root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 15);
    root = Insert(root, 2);
    root = Insert(root, 5);
    root = Insert(root, 3);
    
    if(IsBinarySearchTree(root) == 1){
        printf("Tree is BST\n");
    } else{
        printf("Tree is not BST\n");
    }
}