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

int FindMin(struct TreeNode* root){
    if(root == NULL){
        printf("Error: tree is empty");
        return -1;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int FindMax(struct TreeNode* root){
    if(root == NULL){
        printf("Error: tree is empty");
        return -1;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    struct TreeNode* root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 15);
    root = Insert(root, 2);
    root = Insert(root, 5);
    root = Insert(root, 3);
    
    printf("%d", FindMin(root));
    printf("%d", FindMax(root));
}