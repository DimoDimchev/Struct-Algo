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

struct TreeNode* FindMin(struct TreeNode* root){
    if(root == NULL){
        printf("Error: tree is empty");
        return -1;
    }
    else if(root->left == NULL) return root;
    return FindMin(root->left);
}

struct TreeNode* Delete(struct TreeNode* root, int data){
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if(data > root->data) root->right = Delete(root->right, data);
    else{ // node is the one that needs to be deleted
        // Case 1: node has no children
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        // Case 2: node has a single child
        else if(root->left == NULL){
            struct TreeNode* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            struct TreeNode* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: node has 2 children
        else{
            struct TreeNode* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

// TEST>>>>NOT PART OF IMPLEMENTATION
int main(){
    struct TreeNode* root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 15);
    root = Insert(root, 2);
    root = Insert(root, 5);
    root = Insert(root, 3);
    
    Delete(root, 3);
}